/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_500_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:47:56 by rteles            #+#    #+#             */
/*   Updated: 2022/06/02 14:54:59 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_steps(t_s_swap *l)
{
	if (l->a.max_ra >= l->b.max_ra)
		l->dif_r = l->a.max_ra;
	else
		l->dif_r = l->b.max_ra;
	if (l->a.max_rra >= l->b.max_rra)
		l->dif_rr = l->a.max_rra;
	else
		l->dif_rr = l->b.max_rra;
	l->dif_rr_r = l->a.x + l->b.x;
	if (l->dif_r <= l->dif_rr && l->dif_r <= l->dif_rr_r)
	{
		l->dif = l->dif_r;
		l->select = 1;
		return ;
	}
	else if (l->dif_rr < l->dif_r && l->dif_rr < l->dif_rr_r)
	{
		l->dif = l->dif_rr;
		l->select = 2;
		return ;
	}
	l->dif = l->dif_rr_r;
	l->select = 3;
}

void	swap_postion(t_s_swap *l, t_swap *l_a, t_swap *l_b)
{
	l->a.index = l_a->index;
	l->a.max_ra = l_a->max_ra;
	l->a.max_rra = l_a->max_rra;
	l->a.x = l_a->x;
	l->a.selected = l_a->selected;
	l->b.index = l_b->index;
	l->b.max_ra = l_b->max_ra;
	l->b.max_rra = l_b->max_rra;
	l->b.x = l_b->x;
	l->b.selected = l_b->selected;
	best_steps(l);
}

void	dif_steps(t_s_swap *l, t_swap *swp_a, t_swap *swp_b)
{
	t_s_swap	lst_2;

	swap_postion(&lst_2, swp_a, swp_b);
	if (l->dif > lst_2.dif)
		swap_postion(l, swp_a, swp_b);
}

void	index_small_position_a(t_list **lst_a, t_swap *swp_b, t_s_swap *l)
{
	t_swap	l_a;
	t_list	*temp;
	int		sz_a;
	int		i;

	i = 0;
	temp = *lst_a;
	sz_a = ft_lstsize(temp);
	l_a.index = 2147483647;
	while (temp)
	{
		if (temp->index > swp_b->index && temp->index <= l_a.index)
			index_position(&l_a, temp->index, sz_a, i);
		temp = temp->next;
		i++;
	}
	dif_steps(l, &l_a, swp_b);
}
