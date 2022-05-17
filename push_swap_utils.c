/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:59:15 by rteles            #+#    #+#             */
/*   Updated: 2022/05/17 23:14:07 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
------- SA / SB ------- 	2 -> 1
*/
void	ft_lst_sa(t_list **lstx)
{
	t_list	*temp;
	t_list	*lst;

	lst = *lstx;
	if (lst->next == NULL)
		return ;
	temp = lst->next;
	lst->next = temp->next;
	temp->next = lst;
	*lstx = temp;
}

/*
------- PA / PB -------		1A -> 1B / 1B -> 1A
*/
void	ft_lst_pa(t_list **lstx_1, t_list **lstx_2)
{
	t_list	*temp1;
	t_list	*temp2;
	t_list	*lst_1;
	t_list	*lst_2;

	lst_1 = *lstx_1;
	lst_2 = *lstx_2;
	temp1 = lst_1;
	temp2 = lst_1->next;
	temp1->next = lst_2;
	*lstx_2 = temp1;
	*lstx_1 = temp2;
}

/* ------- RA / RB ------- 	1 -> U	*/

void	ft_lst_ra(t_list **lstx)
{
	t_list	*temp;
	t_list	*lst;

	lst = *lstx;
	temp = ft_lstlast(lst);
	temp->next = lst;
	temp = lst->next;
	lst->next = 0;
	*lstx = temp;
}

/* ------- RRA / RRB ------- 	U -> 1	*/

void	ft_lst_rra(t_list **lstx)
{
	t_list	*temp;
	t_list	*first;
	t_list	*lst;

	lst = *lstx;
	first = lst;
	while (lst->next->next != NULL)
		lst = lst->next;
	temp = lst->next;
	temp->next = first;
	lst->next = 0;
	*lstx = temp;
}
/*-----*/