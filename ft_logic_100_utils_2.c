/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_100_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:05:11 by rteles            #+#    #+#             */
/*   Updated: 2022/05/30 19:22:18 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap	index_max_position(t_list **lst, int min, int max)
{
	t_swap	l_b;
	int		size;
	int		i;
	int		aux;
	t_list	*temp;

	temp = *lst;
	size = ft_lstsize(temp);
	temp = ft_lstlast(temp);
	i = size - 1;
	l_b.index = -1;
	while (temp)
	{
		aux = size - i;
		if (temp->index >= min && temp->index <= max)
		{
			if (l_b.index == -1)
				index_position(&l_b, temp->index, size, i);
			else if (aux > l_b.max_rra)
				index_position(&l_b, temp->index, size, i);
		}
		else
			break ;
		temp = temp->previus;
		i--;
	}
	return (l_b);
}

void	logic_rfs_lst_b(t_list **lst_a, t_list **lst_b, t_range *rg, int *i)
{
	t_s_swap	var;

	(void)lst_a;
	rg->min++;
	var.b = index_max_position(lst_b, rg->min, rg->max);
	if (var.b.index == -1)
		return ;
	if (rg->max + rg->dif < rg->len)
		index_descending(*lst_a, &var.a, rg->min + rg->len, rg->max + rg->len);
	if (var.b.max_rra >= var.a.max_rra)
	{
		logic_while_rrr(lst_a, lst_b, &var, i);
		return ;
	}
	while (--var.b.max_rra >= 0)
		*i = ft_rrb(lst_b, 1);
	//ft_printf("\n\n Index B: %i Max: %i Min: %i \n\n", var.b.index, rg->max, rg->min);
	//ft_printf("\n\n RRA: %i RRB: %i \n\n", var.a.max_rra, var.b.max_rra);
}
