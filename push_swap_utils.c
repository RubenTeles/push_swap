/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:59:15 by rteles            #+#    #+#             */
/*   Updated: 2022/05/30 16:26:25 by rteles           ###   ########.fr       */
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
	t_list	*lst_1;
	t_list	*lst_2;

	lst_1 = *lstx_1;
	temp1 = lst_1;
	temp2 = lst_1->next;
	if (*lstx_2 == NULL)
	{
		temp1 = ft_lstnew(temp1->num);
		temp1->index = lst_1->index;
		temp1->previus = 0;
	}
	else
	{
		lst_2 = *lstx_2;
		temp1->next = lst_2;
		if (lst_2 != 0)
			lst_2->previus = temp1;
	}
	*lstx_2 = temp1;
	if (temp2 != 0)
		temp2->previus = 0;
	*lstx_1 = temp2;
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