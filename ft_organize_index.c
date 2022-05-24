/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_organize_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:01:44 by rteles            #+#    #+#             */
/*   Updated: 2022/05/24 12:11:12 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap	index_list_position(t_list **lst, int min, int max)
{
	t_swap	l_a;
	t_swap	l_b;
	t_list	*temp;
	int		a;
	int		size;

	temp = *lst;
	a = 0;
	size = ft_lstsize(temp);
	while (temp)
	{
		if (temp->index >= min && temp->index <= max && a == 0)
		{
			l_a.max_ra = temp->index;
			l_a.max_rra = size - temp->index;
			if (l_a.max_ra <= l_a.max_rra)
			{
				l_a.selected = 1;
				l_a
			}
			else
				l_a.selected = 0;
			a = 1;
		}
		else if (temp->index >= min && temp->index <= max && a == 1)
		{
			l_b.max_ra = temp->index;
			l_b.max_rra = size - temp->index;
			if (l_b.max_ra <= l_b.max_rra)
				l_b.selected = 1;
			else
				l_b.selected = 0;
		}
		temp = temp->next;
	}
	return (l_a);
}

void	organize_array(int	**index, int i, int aux)
{
	int	*o;
	int	a;

	o = *index;
	while (--i >= 0)
	{
		aux = i;
		while (--aux >= 0)
		{
			if (o[i] < o[aux])
			{
				a = o[i];
				o[i] = o[aux];
				o[aux] = a;
			}
			else if (o[i] == o[aux])
				ft_exit();
		}
	}
	*index = o;
}

void	create_index(t_list *lst_a, int len, int i)
{
	t_list	*temp;
	int		*index;

	temp = lst_a;
	index = (int *)malloc(sizeof(int) * len);
	if (!index)
		ft_exit();
	while (temp)
	{
		index[++i] = temp->num;
		temp = temp->next;
	}
	organize_array(&index, i + 1, 0);
	temp = lst_a;
	while (temp)
	{
		i = 0;
		while (index[i] != temp->num)
			i++;
		if (index[i] == temp->num)
			temp->index = i;
		temp = temp->next;
	}
	free(index);
	lst_a = temp;
}
