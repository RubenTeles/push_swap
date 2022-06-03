/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_500_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:47:56 by rteles            #+#    #+#             */
/*   Updated: 2022/06/03 18:00:18 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_start(t_s_swap *l)
{
	l->a.index = -1;
	l->a.max_ra = 2147483647;
	l->a.max_rra = 2147483647;
	l->a.x = 2147483647;
	l->a.selected = -1;
	l->b.index = -1;
	l->b.max_ra = 2147483647;
	l->b.max_rra = 2147483647;
	l->b.x = 2147483647;
	l->b.selected = -1;
	l->dif_r = 2147483647;
	l->dif_rr = 2147483647;
	l->dif_rr_r = 2147483647;
	l->dif = 2147483647;
	l->select = -1;
}

void	index_logic_position(t_list **l_a, t_list **l_b, t_s_swap *l, int len)
{
	t_list	*temp_begin;
	int		size;
	int		i;
	t_swap	lb;

	i = 0;
	(void)len;
	temp_begin = *l_b;
	size = ft_lstsize(temp_begin);
	swap_start(l);
	while (temp_begin)
	{
		index_position(&lb, temp_begin->index, size, i);
		index_small_position_a(l_a, &lb, l);
		temp_begin = temp_begin->next;
		i++;
	}
}

void	choose_if_500_b(t_list **lst_a, t_list **lst_b, t_s_swap *var, int *i)
{
	if (var->a.selected == 1)
	{
		while (--(var->a.max_ra) >= 0)
			*i = ft_ra(lst_a, 1);
	}
	else if (var->a.selected == 0)
	{
		while (--(var->a.max_rra) >= 0)
			*i = ft_rra(lst_a, 1);
	}
	if (var->b.selected == 1)
	{
		while (--(var->b.max_ra) >= 0)
			*i = ft_rb(lst_b, 1);
	}
	else if (var->b.selected == 0)
	{
		while (--(var->b.max_rra) >= 0)
			*i = ft_rrb(lst_b, 1);
	}
}

void	logic_500_b(t_list **lst_a, t_list **lst_b, int len, int *i)
{
	t_s_swap		var;

	(void)len;
	index_logic_position(lst_a, lst_b, &var, 9);
	if (var.select == 1)
		logic_while_rr(lst_a, lst_b, &var, i);
	else if (var.select == 2)
		logic_while_rrr(lst_a, lst_b, &var, i);
	else
		choose_if_500_b(lst_a, lst_b, &var, i);
	*i = ft_pa(lst_a, lst_b, 1);
}
