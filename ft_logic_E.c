/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_E.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:47:56 by rteles            #+#    #+#             */
/*   Updated: 2022/06/06 15:20:50 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//-------------- LOGIC FOR EXCEPTIONS - UTILS --------------//
int	is_smalest(t_list *list_a)
{
	int		small;
	t_list	*temp;

	small = list_a->index;
	temp = list_a->next;
	while (temp)
	{
		if (temp->index < small)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	index_smalest(t_list **list_a, int *i, int index)
{
	int		small;
	t_list	*temp;
	int		len;

	len = 1;
	small = (*list_a)->begin->index;
	temp = (*list_a)->begin->next;
	while (temp)
	{
		if (small > temp->index)
			index = len;
		temp = temp->next;
		len++;
	}
	len -= index;
	if (len > index)
	{
		while (--index >= 0)
			*i += ft_ra(list_a, 1);
	}
	else
	{
		while (--len >= 0)
			*i += ft_rra(list_a, 1);
	}
}

//-------------- LOGIC FOR EXCEPTIONS --------------//
void	logic_5_2(t_list **lst_a, t_list **lst_b, int *i)
{
	if (((*lst_a)->begin)->next->index > ((*lst_a)->begin)->index)
	{
		if (ft_lstlast((*lst_a))->index > ((*lst_a)->begin)->index)
		{
			if (is_smalest((*lst_a)->begin))
				*i += ft_pb(lst_a, lst_b, 1);
			else
				index_smalest(lst_a, i, 0);
		}
		else
			*i += ft_rra(lst_a, 1);
	}
	else
	{
		if (ft_lstlast((*lst_a))->index > ((*lst_a)->begin)->index)
		{
			if (((*lst_a)->begin)->next->next->index > ((*lst_a)->begin)->index)
				*i += ft_sa(lst_a, 1);
			else
				*i += ft_ra(lst_a, 1);
		}
		else
			index_smalest(lst_a, i, 0);
	}
}

void	logic_exceptions(t_list **lst_a, t_list **lst_b, int *i)
{
	while (is_right((*lst_a)->begin) != 1)
		logic_5_2(lst_a, lst_b, i);
	while (*lst_b != 0)
		i += ft_pa(lst_a, lst_b, 1);
}
