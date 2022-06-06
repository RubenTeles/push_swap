/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_500_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:47:56 by rteles            #+#    #+#             */
/*   Updated: 2022/06/06 14:56:31 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//-------------- Put the List Organized for First Index --------------//
void	first_begin(t_list **lst_a, t_list **lst_b, int *i)
{
	t_swap	list_a;

	(void)lst_b;
	list_a = index_list_position(&(*lst_a)->begin, 0, 0);
	if (list_a.selected == 0)
	{
		while (list_a.max_rra > 0)
		{
			*i += ft_rra(lst_a, 1);
			list_a.max_rra--;
		}
	}
	else
	{
		while (list_a.max_ra > 0)
		{
			*i += ft_ra(lst_a, 1);
			list_a.max_ra--;
		}
	}
}

//-------------- Search Index Using just the Command RA --------------//
t_swap	index_list_position_500(t_list **lst, int min, int max)
{
	t_swap	l_a;
	int		size;
	t_list	*temp;
	int		i;

	i = 0;
	temp = *lst;
	size = ft_lstsize(temp);
	l_a.max_ra = -1;
	l_a.max_rra = -1;
	l_a.selected = 1;
	while (temp)
	{
		if (temp->index >= min && temp->index <= max)
		{
			l_a.index = temp->index;
			l_a.max_ra = i;
			l_a.max_rra = 2147483647;
			l_a.selected = 1;
			break ;
		}
		temp = temp->next;
		i++;
	}
	return (l_a);
}

//----------------- Logic for 100 & 500 Number's for Stack B -----------------//
void	logic_500(t_list **lst_a, t_list **lst_b, int len, int *i)
{
	t_range			range;
	t_s_swap		var;

	chosen_index_plus(&range, len);
	var.a = index_list_position_500(&(*lst_a)->begin, range.min, range.max);
	if (var.a.selected == 0)
	{
		while (var.a.max_rra > 0)
		{
			*i += ft_rra(lst_a, 1);
			var.a.max_rra--;
		}
	}
	else
	{
		while (var.a.max_ra > 0)
		{
			*i += ft_ra(lst_a, 1);
			var.a.max_ra--;
		}
	}
	*i += ft_pb(lst_a, lst_b, 1);
}

//----------------- Logic for 100 and 500 Number's -----------------//
void	logic_number_100_500(t_list **lst_a, t_list **lst_b, int len, int *i)
{
	if (is_right((*lst_a)->begin) == 1)
		return ;
	while (ft_lstsize((*lst_a)->begin) != 5 && is_right((*lst_a)->begin) != 1)
		logic_500(lst_a, lst_b, len, i);
	if (ft_lstsize((*lst_a)->begin) == 5)
		logic_number_5(lst_a, lst_b, i);
	while (*lst_b != 0)
		logic_500_b(lst_a, lst_b, len, i);
	while (is_right((*lst_a)->begin) != 1)
		first_begin(lst_a, lst_b, i);
}
