/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_100_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:05:11 by rteles            #+#    #+#             */
/*   Updated: 2022/06/01 23:26:40 by rteles           ###   ########.fr       */
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

/*void	index_small_position_b(t_list **lst_b, t_swap *swp_a, t_s_swap *l)
{
	t_swap	l_a;
	t_swap	l_b;
	t_list	*temp;
	int		size;
	int		i;

	i = 0;
	temp = *lst_b;
	size = ft_lstsize(temp);
	l_a.index = -1;
	l_b.index = 2147483647;
	while (temp)
	{
		if (temp->index < swp_a->index && temp->index > l_a.index)
			index_position(&l_a, temp->index, size, i);
		else if (temp->index > swp_a->index && temp->index <= l_b.index)
			index_position(&l_b, temp->index, size, i);
		temp = temp->next;
		i++;
	}
	if (l_a.index == -1)
		swap_postion(l, &l_b, swp_a);
	else
		swap_postion(l, &l_a, swp_a);
}*/

t_swap	index_small_position(t_list **lst_b, int index)
{
	t_swap	l_a;
	t_swap	l_b;
	t_list	*temp;
	int		size;
	int		i;

	i = 0;
	temp = *lst_b;
	size = ft_lstsize(temp);
	l_a.index = -1;
	l_b.index = 2147483647;
	while (temp)
	{
		if (temp->index < index && temp->index > l_a.index)
			index_position(&l_a, temp->index, size, i);
		else if (temp->index > index && temp->index <= l_b.index)
			index_position(&l_b, temp->index, size, i);
		temp = temp->next;
		i++;
	}
	//if (index - l_a.index > l_b.index - index || l_a.index == -1)
	//if (l_a.index == -1)
	if (l_a.x > l_b.x || l_a.index == -1)
		return (l_b);
	else
		return (l_a);
}

void	logic_100_3(t_list **lst_a, t_list **lst_b, int len, int *i)
{
	t_range			range;
	t_s_swap		var;
	t_list			*temp;

	(void)len;
	*i = 1;
	temp = *lst_a;
	chosen_index_max_5(&range, *lst_b);
	var.b = index_list_position(lst_b, range.min, range.max);
	if (var.b.selected == 0)
	{
		while (var.b.max_rra > 0)
		{
			*i += ft_rrb(lst_b, 1);
			var.b.max_rra--;
		}
		*i += ft_pa(lst_a, lst_b, 1);
	}
	else
	{
		while (var.b.max_ra > 0)
		{
			*i += ft_rb(lst_b, 1);
			var.b.max_ra--;
		}
		*i += ft_pa(lst_a, lst_b, 1);
	}
}
