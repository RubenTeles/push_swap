/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:05:59 by rteles            #+#    #+#             */
/*   Updated: 2022/06/02 16:39:00 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_right(t_list *list_a)
{
	t_list	*temp;

	temp = list_a;
	while (temp->next)
	{
		if (temp->index + 1 != temp->next->index)
			return (0);
		temp = temp->next;
	}
	return (1);
}

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
			*i += ft_ra(list_a, 1);
	}
	else
	{
		while (--len >= 0)
			*i += ft_rra(list_a, 1);
	}
}

//-------------- OLD LOGIC --------- MAX = 12MOV.
void	logic_5_2(t_list **lst_a, t_list **lst_b, int *i)
{
	if ((*lst_a)->next->num > (*lst_a)->num)
	{
		if (ft_lstlast(*lst_a)->num > (*lst_a)->num)
		{
			if (is_smalest(*lst_a))
				*i += ft_pb(lst_a, lst_b, 1);
			else
				index_smalest(lst_a, i, 0);
		}
		else
			*i += ft_rra(lst_a, 1);
	}
	else
	{
		if (ft_lstlast(*lst_a)->num > (*lst_a)->num)
		{
			if ((*lst_a)->next->next->num > (*lst_a)->num)
				*i += ft_sa(lst_a, 1);
			else
				*i += ft_ra(lst_a, 1);
		}
		else
			index_smalest(lst_a, i, 0);
	}
}

int	logic(t_list *lst_a, t_list *lst_b, int *i)
{
	if (is_right(lst_a->begin) == 1)
		return (0);
	while (ft_lstsize(lst_a->begin) > 3
		&& ft_lstsize(lst_a->begin) <= 5)
		logic_5(&lst_a->begin, &lst_b->begin, i);
	while (is_right(lst_a->begin) != 1)
		logic_3(&lst_a->begin, &lst_b->begin, i);
	if (lst_b->begin->index < lst_b->begin->next->index)
		*i += ft_sb(&lst_b->begin, 1);
	*i += ft_pa(&lst_a->begin, &lst_b->begin, 1);
	*i += ft_pa(&lst_a->begin, &lst_b->begin, 1);
	return (1);
}

void	first_begin(t_list **lst_a, t_list **lst_b, int *i)
{
	t_swap	list_a;

	(void)lst_b;
	list_a = index_list_position(lst_a, 0, 0);
	if (list_a.selected == 0)
	{
		while (list_a.max_rra > 0)
		{
			*i += ft_rra(lst_a, 1);
			list_a.max_rra--;
		}
	}
	else
	{
		while (list_a.max_ra > 0)
		{
			*i += ft_ra(lst_a, 1);
			list_a.max_ra--;
		}
	}
}

int	verific_list(t_list *lst_a, t_list *lst_b, int len)
{
	int		i;

	i = 0;
	if (len == 2 && (lst_a->num > lst_a->next->num))
		i += ft_sa(&lst_a->begin, 1);
	else if (len == 3)
	{
		while (is_right(lst_a->begin) != 1)
			logic_3(&lst_a->begin, &lst_b->begin, &i);
	}
	else if (len == 5)
		return (logic(lst_a, lst_b, &i));
	else if (len == 4 && len <= 10)
	{
		while (is_right(lst_a->begin) != 1)
			logic_5_2(&lst_a->begin, &lst_b->begin, &i);
		while (ft_lstsize(lst_b->begin) != 0)
			i += ft_pa(&lst_a->begin, &lst_b->begin, 1);
	}
	else if (len == 200)
	{
		if (is_right(lst_a->begin) == 1)
			return (0);
		while (ft_lstsize(lst_a->begin) != 5 && is_right(lst_a->begin) != 1)
			logic_100(&lst_a->begin, &lst_b->begin, len, &i);
		if (ft_lstsize(lst_a->begin) == 5)
			logic(lst_a, lst_b, &i);
		while (ft_lstsize(lst_b->begin) != 0)
		{
			if (lst_a->begin->index > lst_a->begin->next->index)
				ft_sa(&lst_a->begin, 1);
			logic_100_3(&lst_a->begin, &lst_b->begin, len, &i);
		}
		if (lst_a->begin->index > lst_a->begin->next->index)
			ft_sa(&lst_a->begin, 1);
	}
	else
	{
		if (is_right(lst_a->begin) == 1)
			return (0);
		while (ft_lstsize(lst_a->begin) != 5 && is_right(lst_a->begin) != 1)
			logic_500(&lst_a->begin, &lst_b->begin, len, &i);
		if (ft_lstsize(lst_a->begin) == 5)
			logic(lst_a, lst_b, &i);
		while (ft_lstsize(lst_b->begin) != 0)
			logic_500_b(&lst_a->begin, &lst_b->begin, len, &i);
		while (is_right(lst_a->begin) != 1)
			first_begin(&lst_a->begin, &lst_b->begin, &i);
			/*if (lst_a->begin->index > lst_a->begin->next->index)
				ft_sa(&lst_a->begin, 1);*/
		/*	while (ft_lstsize(lst_b->begin) != 0)
		{
			if (lst_a->begin->index > lst_a->begin->next->index)
				ft_sa(&lst_a->begin, 1);
			logic_100_3(&lst_a->begin, &lst_b->begin, len, &i);
		}*/
		//if (lst_a->begin->index > lst_a->begin->next->index)
		//	ft_sa(&lst_a->begin, 1);
			//len = ft_lstsize(lst_a->begin);
			//while (ft_lstsize(lst_b->begin) != 5)
			//	logic_500_b(&lst_a->begin, &lst_b->begin, len, &i);
			//break ;
		//}
		//if (lst_a->begin->index > lst_a->begin->next->index)
		//	ft_sa(&lst_a->begin, 1);
	}
		//	ft_printf("\nSIZE: %i", ft_lstsize(lst_a->begin));
			//show_list(&lst_a->begin, &lst_b->begin);
			/*ft_printf("\n\n LEN: %i", len);*/
			//ft_printf("\n \033[0;32m------ Passos: %i ------\033[0m", i);		
	return (0);
}
	/*show_list(&lst_a->begin, &lst_b->begin);
	ft_printf("\n");
	ft_printf("\n \033[0;32m------ Passos: %i ------\033[0m", i);*/
/*show_list(&lst_a->begin, &lst_b->begin);
		ft_printf("\n");*/
		/*show_list(&lst_a->begin, &lst_b->begin);
		ft_printf("\n");*/
//