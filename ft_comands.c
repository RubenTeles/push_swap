/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comands.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:59:15 by rteles            #+#    #+#             */
/*   Updated: 2022/06/06 18:16:30 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ------- SA / SB ------- 	2 -> 1 */
void	ft_lst_sa(t_list **lstx)
{
	t_list	*temp;
	t_list	*lst;

	lst = *lstx;
	if (lst->next == NULL)
		return ;
	lst->previus = lst->next;
	lst->next = lst->next->next;
	if (lst->next != NULL)
		lst->next->previus = lst;
	temp = lst->previus;
	temp->next = lst;
	temp->previus = 0;
	*lstx = temp;
}

/* ------- PA / PB -------		1A -> 1B / 1B -> 1A */
void	ft_lst_pa(t_list **lstx_1, t_list **lstx_2)
{
	t_list	*temp1;
	t_list	*temp2;

	if ((*lstx_1)->begin->next != NULL)
		temp1 = (*lstx_1)->begin->next;
	else
		temp1 = NULL;
	temp2 = (*lstx_1)->begin;
	if (*lstx_2 == 0)
		temp2->next = 0;
	else
	{
		temp2->next = (*lstx_2)->begin;
		temp2->next->previus = temp2;
	}
	temp2->begin = temp2;
	if (temp1 != NULL)
	{
		temp1->previus = 0;
		temp1->begin = temp1;
	}
	*lstx_1 = temp1;
	*lstx_2 = temp2;
}
/* ------- RA / RB ------- 	1 -> U	*/

void	ft_lst_ra(t_list **lstx)
{
	t_list	*temp;
	t_list	*lst_2;
	t_list	*lst;

	lst = *lstx;
	lst_2 = lst->next;
	lst_2->previus = 0;
	temp = ft_lstlast(lst);
	temp->next = lst;
	lst->previus = temp;
	lst->next = 0;
	*lstx = lst_2;
}

/* ------- RRA / RRB ------- 	U -> 1	*/
void	ft_lst_rra(t_list **lstx)
{
	t_list	*temp;
	t_list	*first;
	t_list	*lst;

	lst = *lstx;
	first = lst;
	temp = ft_lstlast(lst);
	temp->previus->next = 0;
	temp->next = first;
	temp->previus = 0;
	first->previus = temp;
	*lstx = temp;
}
/*-----*/