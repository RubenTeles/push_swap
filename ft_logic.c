/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:05:59 by rteles            #+#    #+#             */
/*   Updated: 2022/06/04 00:32:11 by rteles           ###   ########.fr       */
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

int	logic(t_list **lst_a, t_list **lst_b, int len)
{
	int		i;

	i = 0;
	if (len == 2 && ((*lst_a)->num > (*lst_a)->next->num))
		i += ft_sa(&(*lst_a)->begin, 1);
	else if (len == 3)
		logic_number_3(&(*lst_a), &(*lst_b), &i);
	else if (len == 5)
		logic_number_5(&(*lst_a), &(*lst_b), &i);
	else if (len == 4 || len == 7)
	{
		while (is_right((*lst_a)->begin) != 1)
			logic_5_2(&(*lst_a)->begin, &(*lst_b)->begin, &i);
		while (ft_lstsize((*lst_b)->begin) != 0)
			i += ft_pa(&(*lst_a)->begin, &(*lst_b)->begin, 1);
	}
	else
		logic_number_100_500(&(*lst_a), &(*lst_b), len, &i);
	return (0);
}
	//ft_printf("\n \033[0;32m------ Passos: %i ------\033[0m", i);	
//	ft_printf("\nSIZE: %i", ft_lstsize(lst_a->begin));
			//show_list(&lst_a->begin, &lst_b->begin);
			/*ft_printf("\n\n LEN: %i", len);*/
			//	
	/*
	ft_printf("\n");
	ft_printf("\n \033[0;32m------ Passos: %i ------\033[0m", i);*/
/*show_list(&lst_a->begin, &lst_b->begin);
		ft_printf("\n");*/
		/*show_list(&lst_a->begin, &lst_b->begin);
		ft_printf("\n");*/
//