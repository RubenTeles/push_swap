/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:05:59 by rteles            #+#    #+#             */
/*   Updated: 2022/05/23 18:31:34 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_right(t_list *list_a)
{
	t_list	*temp;

	temp = list_a;
	while (temp->next)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	is_smalest(t_list *list_a)
{
	int		small;
	t_list	*temp;

	small = list_a->num;
	temp = list_a->next;
	while (temp)
	{
		if (temp->num < small)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	index_smalest(t_list **list_a, int *i)
{
	int		small;
	t_list	*temp;
	int		len;
	int		index;

	len = 1;
	index = 0;
	small = (*list_a)->num;
	temp = (*list_a)->next;
	while (temp)
	{
		if (small > temp->num)
			index = len;
		temp = temp->next;
		len++;
	}
	if ((len - index) > index)
	{
		while (--index >= 0)
			*i += ft_ra(list_a);
	}
	else
		while (((--len) - index) >= 0)
			*i += ft_rra(list_a);
}

void	logic(t_list **lst_a, t_list **lst_b, int *i)
{
	if ((*lst_a)->next->num > (*lst_a)->num)
	{
		if (ft_lstlast(*lst_a)->num > (*lst_a)->num)
		{
			if (is_smalest(*lst_a))
				*i += ft_pb(lst_a, lst_b);
			else
				index_smalest(lst_a, i);
		}
		else
			*i += ft_rra(lst_a);
	}
	else
	{
		if (ft_lstlast(*lst_a)->num > (*lst_a)->num)
		{
			if ((*lst_a)->next->next->num > (*lst_a)->num)
				*i += ft_sa(lst_a);
			else
				*i += ft_ra(lst_a);
		}
		else
			*i += ft_ra(lst_a);
	}
}

int	verific_list(t_list *lst_a, t_list *lst_b, int len)
{
	int	i;

	i = 0;
	(void)len;
	while (is_right(lst_a->begin) != 1)
	{
		logic(&lst_a->begin, &lst_b->begin, &i);
	}
	while (ft_lstsize(lst_b->begin) != 0)
	{
		if (ft_lstsize(lst_b) > 0 && is_right(lst_a->begin) == 1)
			i += ft_pa(&lst_a->begin, &lst_b->begin);
	}
	return (0);
}

/*		//ft_printf("\n");
		//show_list(&lst_a->begin, &lst_b->begin);
		//ft_printf("\n");
		//show_list(&lst_a->begin, &lst_b->begin);
	//ft_printf("\n ------ Passos: %i ------", i);*/