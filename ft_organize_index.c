/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_organize_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:01:44 by rteles            #+#    #+#             */
/*   Updated: 2022/06/04 15:02:39 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_crescent(t_list *temp, t_swap *l, int min, int max)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(temp);
	while (temp)
	{
		if (temp->index >= min && temp->index <= max)
		{
			index_position(l, temp->index, size, i);
			break ;
		}
		temp = temp->next;
		i++;
	}
}

void	index_descending(t_list *temp, t_swap *l, int min, int max)
{
	int	size;
	int	i;

	size = ft_lstsize(temp);
	temp = ft_lstlast(temp);
	i = size - 1;
	while (temp)
	{
		if (temp->index >= min && temp->index <= max)
		{
			index_position(l, temp->index, size, i);
			break ;
		}
		temp = temp->previus;
		i--;
	}
}

t_swap	index_list_position(t_list **lst, int min, int max)
{
	t_swap	l_a;
	t_swap	l_b;
	t_list	*temp;

	temp = *lst;
	index_crescent(temp, &l_a, min, max);
	index_descending(temp, &l_b, min, max);
	if (l_b.x < l_a.x)
		return (l_b);
	else
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
