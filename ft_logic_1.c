/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:47:56 by rteles            #+#    #+#             */
/*   Updated: 2022/05/27 16:55:47 by rteles           ###   ########.fr       */
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

//----------------- Logic for 5 Number's -----------------
void	logic_5(t_list **lst_a, t_list **lst_b, int *i)
{
	t_swap	list_a;
	t_swap	list_b;
	t_range	range;

	chosen_index_min_5(&range, *lst_a);
	(void)list_b;
	(void)lst_b;
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

//----------------- Logic for 100 Number's -----------------
/*void	logic_100(t_list **lst_a, t_list **lst_b, int len, int *i)
{
	t_range			range;
	t_s_swap		var;

	chosen_index_plus(&range, len);
	var.a = index_list_position(lst_a, range.min, range.max);
	//	ft_printf("\nIndex = %i\n", var.a.index);
	if (ft_lstsize(*lst_b) >= 2)
	{
		var.b = index_small_position(lst_b, 0, var.a.index);
		if (var.b.max_rra > var.b.max_ra)
		{
			if (var.a.max_rra > var.a.max_ra)
				logic_while_rr(lst_a, lst_b, &var, i);
			else
				logic_100_2(lst_a, lst_b, &var, i);
		}
		else
		{
			if (var.a.max_rra > var.a.max_ra)
				logic_100_2(lst_a, lst_b, &var, i);
			else
				logic_while_rrr(lst_a, lst_b, &var, i);
		}
	}
	logic_100_1(lst_a, lst_b, &var.a, i);
}*/

void	logic_100(t_list **lst_a, t_list **lst_b, int len, int *i)
{
	t_range			range;
	t_s_swap		var;

	chosen_index_plus(&range, len);
	var.a = index_list_position(lst_a, range.min, range.max);
	/*if (ft_lstsize(*lst_b) >= 2)
	{
		var.b = index_small_position(lst_b, var.a.index, var.a.index);
				ft_printf("\nIndex A = %i Index B = %i\n", var.a.index, var.b.index);
		if (var.b.max_rra > var.b.max_ra)
		{
			if (var.a.max_rra > var.a.max_ra)
				logic_while_rr(lst_a, lst_b, &var, i);
			else
				logic_100_2(lst_a, lst_b, &var, i);
		}
		else
		{
			if (var.a.max_rra > var.a.max_ra)
				logic_100_2(lst_a, lst_b, &var, i);
			else
				logic_while_rrr(lst_a, lst_b, &var, i);
		}
	}*/
	logic_100_1(lst_a, lst_b, &var.a, i);
}

void	logic_100_2(t_list **lst_a, t_list **lst_b, t_s_swap *var, int *i)
{
	int	rr;
	int	rrr;

	rr = var->a.max_rra - var->b.max_rra;
	rrr = var->a.max_ra - var->b.max_ra;
	if (rr < 0)
		rr *= -1;
	if (rrr < 0)
		rrr *= -1;
	if (rr < rrr)
		logic_while_rr(lst_a, lst_b, var, i);
	else
		logic_while_rrr(lst_a, lst_b, var, i);
}

void	logic_100_1(t_list **lst_a, t_list **lst_b, t_swap *var_a, int *i)
{
	if (var_a->selected == 0)
	{
		while (var_a->max_rra > 0)
		{
			*i += ft_rra(lst_a, 1);
			var_a->max_rra--;
		}
		*i += ft_pb(lst_a, lst_b, 1);
	}
	else
	{
		while (var_a->max_ra > 0)
		{
			*i += ft_ra(lst_a, 1);
			var_a->max_ra--;
		}
		*i += ft_pb(lst_a, lst_b, 1);
	}
}
