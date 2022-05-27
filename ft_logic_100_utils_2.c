/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_100_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:05:11 by rteles            #+#    #+#             */
/*   Updated: 2022/05/28 00:37:28 by rteles           ###   ########.fr       */
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

	i = 0;
	temp = *lst;
	size = ft_lstsize(temp);
	temp = ft_lstlast(temp);
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

	var.b = index_max_position(lst_b, rg->min, rg->max);
	if (var.b.index == -1)
		return ;
	chosen_index_plus(rg, rg->len);
	index_descending(*lst_a, &var.a, rg->min, rg->max);
	if (var.b.max_rra >= var.a.max_rra)
	{
		logic_while_rrr(lst_a, lst_b, &var, i);
		return ;
	}
	chosen_index_plus(rg, -1);
	while (--var.b.max_rra >= 0)
		ft_rb(lst_b, 1);
}
