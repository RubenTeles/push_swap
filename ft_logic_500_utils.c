/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_500_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:47:56 by rteles            #+#    #+#             */
/*   Updated: 2022/06/02 17:05:13 by rteles           ###   ########.fr       */
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

void	logic_500_b(t_list **lst_a, t_list **lst_b, int len, int *i)
{
	t_s_swap		var;

	(void)len;
	index_logic_position(lst_a, lst_b, &var, 9);
	if (var.select == 1)// r 
		logic_while_rr(lst_a, lst_b, &var, i);
	else if (var.select == 2)// rr
		logic_while_rrr(lst_a, lst_b, &var, i);
	else
	{
		if (var.a.selected == 1)
		{
			while (--(var.a.max_ra) >= 0)
				*i = ft_ra(lst_a, 1);
		}
		else if (var.a.selected == 0)
		{
			while (--(var.a.max_rra) >= 0)
				*i = ft_rra(lst_a, 1);
		}
		if (var.b.selected == 1)
		{
			while (--(var.b.max_ra) >= 0)
				*i = ft_rb(lst_b, 1);
		}
		else if (var.b.selected == 0)
		{
			while (--(var.b.max_rra) >= 0)
				*i = ft_rrb(lst_b, 1);
		}
	}
	*i = ft_pa(lst_a, lst_b, 1);
}

t_swap	index_list_position_500(t_list **lst, int min, int max)
{
	t_swap	l_a;
	int		size;
	t_list	*temp;
	int		i;

	i = 0;
	temp = *lst;
	size = ft_lstsize(temp);
	while (1)
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

void	chosen_index_divide(t_range *range, int len)
{
	static int		c = 1;
	static int		i = -1;
	int				aux;
	int				div;

	i++;
	if (len > 100)
		div = 5 + (len / 80);
	else
		div = 5;
	range->len = len - 6;
	aux = (range->len / div) * c;
	if (aux > range->len)
		aux = range->len;
	if (i > aux)
		c++;
	aux = (range->len / div) * c;
	if (aux > range->len)
		aux = range->len;
	range->max = aux;
	range->c = aux - i;
	aux = c - 1;
	range->min = (range->len / div) * aux;
	range->dif = range->max - range->min;
		//ft_printf("\n\n Min = %i Max = %i Range = %i\n" ,range->min, range->max, range->len);//(len / 200);
}

//----------------- Logic for 500 Number's -----------------
void	logic_500(t_list **lst_a, t_list **lst_b, int len, int *i)
{
	t_range			range;
	t_s_swap		var;

	chosen_index_plus(&range, len);
	var.a = index_list_position_500(lst_a, range.min, range.max);
	/*if (ft_lstsize(*lst_b) >= 2)
	{
		var.b = index_small_position(lst_b, var.a.index);
		if (var.b.max_ra <= var.b.max_rra)
		{
			if (var.a.max_ra <= var.b.max_ra)
				logic_while_rr(lst_a, lst_b, &var, i);
		}
	}*/
	logic_100_1(lst_a, lst_b, &var.a, i);
	*i += ft_pb(lst_a, lst_b, 1);
}
