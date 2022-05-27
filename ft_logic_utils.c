/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:05:11 by rteles            #+#    #+#             */
/*   Updated: 2022/05/27 14:43:48 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	chosen_index_plus(t_range *range, int len)
{
	static int		c = 1;
	static int		i = -1;
	int				aux;

	i++;
	range->len = len - 6;
	//ft_printf("\n Len: %i \n", range->len);
	aux = (range->len / 4) * c;
	if (aux > range->len)
		aux = range->len;
	//	ft_printf("\nAUX: %i - %i x", aux, i);
	if (i > aux)
		c++;
	aux = (range->len / 4) * c;
	if (aux > range->len)
		aux = range->len;
	range->max = aux;
	aux = c - 1;
	range->min = (range->len / 4) * aux;
	//	ft_printf("\n\n Chose: Min = %i Max = %i" ,range->min, range->max);
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

	if (c == 1)
	{
		c = 0;
		return ;
	}
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
			//ft_printf("\nNumber: %i Min: %i\n", lst->num, lst->index);
		}
		else if (lst->index > range->min)
		{
			range->min = lst->index;
			//ft_printf("\nNumber: %i Min: %i\n", lst->num, lst->index);
		}
		lst = lst->next;
	}
	c = 1;
}
