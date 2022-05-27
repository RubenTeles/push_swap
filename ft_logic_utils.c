/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:05:11 by rteles            #+#    #+#             */
/*   Updated: 2022/05/28 00:36:55 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chosen_index_plus(t_range *range, int len)
{
	static int		c = 1;
	static int		i = -1;
	int				aux;
	int				div;

	if (len < 0)
	{
		i--;
		return ;
	}
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
	aux = c - 1;
	range->min = (range->len / div) * aux;
	range->dif = range->max - range->min;
	range->c = i - aux;
		//ft_printf("\n\n Min = %i Max = %i Range = %i\n" ,range->min, range->max, range->len);//(len / 200);
}

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

void	chosen_index_max_5(t_range *range, t_list *lst)
{
	static int		c = -1;

	if (--c == 0)
		return ;
	else
	{
		range->min = -1;
		range->max = -1;
	}
	while (lst)
	{
		if (lst->index > range->max)
		{
			range->min = range->max;
			range->max = lst->index;
		}
		else if (lst->index > range->min)
			range->min = lst->index;
		lst = lst->next;
	}
	if (range->min == -1)
		range->min = range->max;
	c = 1;
}
