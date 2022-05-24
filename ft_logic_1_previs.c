/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_1_previs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:47:56 by rteles            #+#    #+#             */
/*   Updated: 2022/05/24 16:07:01 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	index_smalest_fake(t_list **list_a, int *i, int index)
{
	int		small;
	t_list	*temp;
	int		len;

	len = 1;
	small = (*list_a)->num;
	temp = (*list_a)->next;
	while (temp)
	{
		if (small > temp->num)
			index = len;
		temp = temp->next;
		len++;
	}
	len -= index;
	if (len > index)
	{
		while (--index >= 0)
			*i += ft_ra(list_a, 0);
	}
	else
	{
		while (--len >= 0)
			*i += ft_rra(list_a, 0);
	}
}

void	logic_5_2_previs(t_list **lst_a, t_list **lst_b, int *i)
{
	if ((*lst_a)->next->num > (*lst_a)->num)
	{
		if (ft_lstlast(*lst_a)->num > (*lst_a)->num)
		{
			if (is_smalest(*lst_a))
				*i += ft_pb(lst_a, lst_b, 0);
			else
				index_smalest_fake(lst_a, i, 0);
		}
		else
			*i += ft_rra(lst_a, 0);
	}
	else
	{
		if (ft_lstlast(*lst_a)->num > (*lst_a)->num)
		{
			if ((*lst_a)->next->next->num > (*lst_a)->num)
				*i += ft_sa(lst_a, 0);
			else
				*i += ft_ra(lst_a, 0);
		}
		else
			index_smalest_fake(lst_a, i, 0);
	}
}

//----------------- Logic for 3 Number's -----------------
void	logic_3_previs(t_list **lst_a, t_list **lst_b, int *i)
{
	(void)lst_b;
	if ((*lst_a)->num > (*lst_a)->next->num)
	{
		if ((*lst_a)->num > (*lst_a)->next->next->num)
				*i += ft_ra(lst_a, 0);
		else
			*i += ft_sa(lst_a, 0);
	}
	else
	{
		if ((*lst_a)->num > (*lst_a)->next->next->num)
				*i += ft_ra(lst_a, 0);
		else
			*i += ft_sa(lst_a, 0);
	}
}

//----------------- Logic for 5 Number's -----------------
void	logic_5_previs(t_list **lst_a, t_list **lst_b, int *i)
{
	t_swap	list_a;
	t_swap	list_b;

	(void)list_b;
	(void)lst_b;
	list_a = index_list_position(lst_a, 0, 1);
	if (list_a.selected == 0)
	{
		while (list_a.max_rra > 0)
		{
			*i += ft_rra(lst_a, 0);
			list_a.max_rra--;
		}
		*i += ft_pb(lst_a, lst_b, 0);
	}
	else
	{
		while (list_a.max_ra > 0)
		{
			*i += ft_ra(lst_a, 0);
			list_a.max_ra--;
		}
		*i += ft_pb(lst_a, lst_b, 0);
	}
}

int	logic_previs(t_list *lst_a, t_list *lst_b)
{
	int		i;
	int		a;
	t_list	*temp1;
	t_list	*temp2;

	temp1 = lst_a;
	temp2 = lst_b;
	i = 0;
	a = 0;
	if (is_right(lst_a) == 1)
		return (0);
	while (ft_lstsize(lst_b) >= 0 && ft_lstsize(lst_b) < 2)
		logic_5_previs(&lst_a, &lst_b, &i);
	while (is_right(lst_a) != 1)
		logic_3_previs(&lst_a, &lst_b, &i);
	i += ft_pa(&lst_a, &lst_b, 0);
	i += ft_pa(&lst_a, &lst_b, 0);
	while (is_right(temp1) != 1)
		logic_5_previs(&temp1, &temp2, &a);
	while (ft_lstsize(temp2) != 0)
		a += ft_pa(&temp1, &temp2, 0);
	if (a > i)
		return (0);
	return (1);
}
