/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:05:59 by rteles            #+#    #+#             */
/*   Updated: 2022/05/24 12:08:21 by rteles           ###   ########.fr       */
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

void	index_smalest(t_list **list_a, int *i, int index)
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
			*i += ft_ra(list_a);
	}
	else
	{
		while (--len >= 0)
			*i += ft_rra(list_a);
	}
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
				index_smalest(lst_a, i, 0);
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
			index_smalest(lst_a, i, 0);
	}
}

int	verific_list(t_list *lst_a, t_list *lst_b, int len)
{
	int	i;

	i = 0;
	(void)len;
	if (len == 2 && (lst_a->num > lst_a->next->num))
		i += ft_sa(&lst_a->begin);
	else if (len == 3)
	{
		while (is_right(lst_a->begin) != 1)
			logic_3(&lst_a->begin, &lst_b->begin, &i);
	}
	else if (len <= 5)
	{
		while (is_right(lst_a->begin) != 1)
			logic(&lst_a->begin, &lst_b->begin, &i);
		while (ft_lstsize(lst_b->begin) != 0)
			i += ft_pa(&lst_a->begin, &lst_b->begin);
	}
	/*show_list(&lst_a->begin, &lst_b->begin);
	ft_printf("\n");
	ft_printf("\n \033[0;32m------ Passos: %i ------\033[0m", i);*/
	return (0);
}
	
/*show_list(&lst_a->begin, &lst_b->begin);
		ft_printf("\n");*/
		/*show_list(&lst_a->begin, &lst_b->begin);
		ft_printf("\n");*/
//