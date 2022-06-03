/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:05:59 by rteles            #+#    #+#             */
/*   Updated: 2022/06/03 17:44:31 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//----------------- Logic for 5 Number's - UTILS -----------------//
void	chosen_index_min_5(t_range *range, t_list *lst)
{
	static int		c = -1;

	if (c == 1)
	{
		c = 0;
		return ;
	}
	else
	{
		range->min = 2147483647;
		range->max = 2147483647;
	}
	while (lst)
	{
		if (lst->index <= range->min)
		{
			range->max = range->min;
			range->min = lst->index;
		}
		else if (lst->index < range->max)
			range->max = lst->index;
		lst = lst->next;
	}
	c = 1;
}

//----------------- Logic for 5 Number's -----------------//
void	logic_5(t_list **lst_a, t_list **lst_b, int *i)
{
	t_swap	list_a;
	t_range	range;

	(void)lst_b;
	chosen_index_min_5(&range, *lst_a);
	list_a = index_list_position(lst_a, range.min, range.max);
	if (list_a.selected == 0)
	{
		while (list_a.max_rra > 0)
		{
			*i += ft_rra(lst_a, 1);
			list_a.max_rra--;
		}
		*i += ft_pb(lst_a, lst_b, 1);
	}
	else
	{
		while (list_a.max_ra > 0)
		{
			*i += ft_ra(lst_a, 1);
			list_a.max_ra--;
		}
		*i += ft_pb(lst_a, lst_b, 1);
	}
}

//----------------- Logic for 5 Number's -----------------//
void	logic_number_5(t_list *lst_a, t_list *lst_b, int *i)
{
	if (is_right(lst_a->begin) == 1)
		return ;
	while (ft_lstsize(lst_a->begin) > 3
		&& ft_lstsize(lst_a->begin) <= 5)
		logic_5(&lst_a->begin, &lst_b->begin, i);
	while (is_right(lst_a->begin) != 1)
		logic_3(&lst_a->begin, &lst_b->begin, i);
	if (lst_b->begin->index < lst_b->begin->next->index)
		*i += ft_sb(&lst_b->begin, 1);
	*i += ft_pa(&lst_a->begin, &lst_b->begin, 1);
	*i += ft_pa(&lst_a->begin, &lst_b->begin, 1);
}
