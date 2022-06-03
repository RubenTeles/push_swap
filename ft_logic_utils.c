/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:05:11 by rteles            #+#    #+#             */
/*   Updated: 2022/06/04 00:16:13 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	logic_while_rr(t_list **lst_a, t_list **lst_b, t_s_swap *var, int *i)
{
	int	max_ra;
	int	max_rb;

	max_ra = var->a.max_ra;
	max_rb = var->b.max_ra;
	while (max_ra > 0 || max_rb > 0)
	{
		if (max_ra > 0 && max_rb > 0)
			i += ft_rr(lst_a, lst_b, 1);
		else if (max_ra > 0 && max_rb <= 0)
			i += ft_ra(lst_a, 1);
		else
			i += ft_rb(lst_b, 1);
		max_ra--;
		max_rb--;
	}
	var->a.max_ra = max_ra;
	var->b.max_ra = max_rb;
}

void	logic_while_rrr(t_list **lst_a, t_list **lst_b, t_s_swap *var, int *i)
{
	int	max_rra;
	int	max_rrb;

	max_rra = var->a.max_rra;
	max_rrb = var->b.max_rra;
	while (max_rra > 0 || max_rrb > 0)
	{
		if (max_rra > 0 && max_rrb > 0)
			i += ft_rrr(lst_a, lst_b, 1);
		else if (max_rra > 0 && max_rrb <= 0)
			i += ft_rra(lst_a, 1);
		else
			i += ft_rrb(lst_b, 1);
		max_rra--;
		max_rrb--;
	}
	var->a.max_rra = max_rra;
	var->b.max_rra = max_rrb;
}

void	chosen_index_plus(t_range *range, int len)
{
	static int		c = 1;
	static int		i = -1;
	int				aux;
	int				div;

	i++;
	if (len >= 250)
		div = len / 150;
	else
		div = 2;
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
}

void	index_position(t_swap *l, int index, int size, int i)
{
	l->index = index;
	l->max_ra = i;
	l->max_rra = size - i;
	if (l->max_ra <= l->max_rra)
	{
		l->x = l->max_ra;
		l->selected = 1;
	}
	else
	{
		l->x = l->max_rra;
		l->selected = 0;
	}
}
