/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:47:56 by rteles            #+#    #+#             */
/*   Updated: 2022/05/24 17:12:24 by rteles           ###   ########.fr       */
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

	(void)list_b;
	(void)lst_b;
	list_a = index_list_position(lst_a, 0, 1);
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
/*void	logic_5x(t_list **lst_a, t_list **lst_b, int *i)
{
	static	min;
	static	max;
	t_swap	list_a;
	t_swap	list_b;

	(void)list_b;
	(void)lst_b;
	list_a = index_list_position(lst_a, 0, 1);
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
}*/