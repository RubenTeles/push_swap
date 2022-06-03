/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_3_E.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:47:56 by rteles            #+#    #+#             */
/*   Updated: 2022/06/03 18:19:52 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//----------------- Logic for 3 Number's -----------------
void	logic_3(t_list **lst_a, t_list **lst_b, int *i)
{
	(void)lst_b;
	if ((*lst_a)->num > (*lst_a)->next->num)
	{
		if ((*lst_a)->num > (*lst_a)->next->next->num)
				*i += ft_ra(lst_a, 1);
		else
		{
			if (ft_lstsize(*lst_b) == 2 && (*lst_b)->num < (*lst_b)->next->num)
				*i += ft_ss(lst_a, lst_b, 1);
			else
				*i += ft_sa(lst_a, 1);
		}
	}
	else
	{
		if ((*lst_a)->num > (*lst_a)->next->next->num)
				*i += ft_rra(lst_a, 1);
		else
		{
			if (ft_lstsize(*lst_b) == 2 && (*lst_b)->num < (*lst_b)->next->num)
				*i += ft_ss(lst_a, lst_b, 1);
			else
				*i += ft_sa(lst_a, 1);
		}
	}
}

void	logic_number_3(t_list *lst_a, t_list *lst_b, int *i)
{
	while (is_right(lst_a->begin) != 1)
		logic_3(&lst_a->begin, &lst_b->begin, i);
}

//-------------- LOGIC FOR EXCEPTIONS - UTILS --------------//
int	is_smalest(t_list *list_a)
{
	int		small;
	t_list	*temp;

	small = list_a->index;
	temp = list_a->next;
	while (temp)
	{
		if (temp->index < small)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	index_smalest(t_list **list_a, int *i, int index)
{
	int		small;
	t_list	*temp;
	int		len;

	len = 1;
	small = (*list_a)->num;
	temp = (*list_a)->next;
	while (temp)
	{
		if (small > temp->num)
			index = len;
		temp = temp->next;
		len++;
	}
	len -= index;
	if (len > index)
	{
		while (--index >= 0)
			*i += ft_ra(list_a, 1);
	}
	else
	{
		while (--len >= 0)
			*i += ft_rra(list_a, 1);
	}
}

//-------------- LOGIC FOR EXCEPTIONS --------------//
void	logic_5_2(t_list **lst_a, t_list **lst_b, int *i)
{
	if ((*lst_a)->next->num > (*lst_a)->num)
	{
		if (ft_lstlast(*lst_a)->num > (*lst_a)->num)
		{
			if (is_smalest(*lst_a))
				*i += ft_pb(lst_a, lst_b, 1);
			else
				index_smalest(lst_a, i, 0);
		}
		else
			*i += ft_rra(lst_a, 1);
	}
	else
	{
		if (ft_lstlast(*lst_a)->num > (*lst_a)->num)
		{
			if ((*lst_a)->next->next->num > (*lst_a)->num)
				*i += ft_sa(lst_a, 1);
			else
				*i += ft_ra(lst_a, 1);
		}
		else
			index_smalest(lst_a, i, 0);
	}
}