/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_3_E.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:47:56 by rteles            #+#    #+#             */
/*   Updated: 2022/06/06 15:19:06 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	logic_3_util(t_list **lst_a, t_list **lst_b, int *i)
{
	if ((*lst_b) != NULL && ft_lstsize((*lst_b)->begin) == 2
		&& (*lst_b)->begin->num < (*lst_b)->begin->next->num)
		*i += ft_ss(lst_a, lst_b, 1);
	else
		*i += ft_sa(lst_a, 1);
}

//----------------- Logic for 3 Number's -----------------
void	logic_3(t_list **lst_a, t_list **lst_b, int *i)
{
	if ((*lst_a)->begin->num > (*lst_a)->begin->next->num)
	{
		if ((*lst_a)->begin->num > (*lst_a)->begin->next->next->num)
				*i += ft_ra(lst_a, 1);
		else
			logic_3_util(lst_a, lst_b, i);
	}
	else
	{
		if ((*lst_a)->begin->num > (*lst_a)->begin->next->next->num)
				*i += ft_rra(lst_a, 1);
		else
			logic_3_util(lst_a, lst_b, i);
	}
}

void	logic_number_3(t_list **lst_a, t_list **lst_b, int *i)
{
	while (is_right((*lst_a)->begin) != 1)
		logic_3(lst_a, lst_b, i);
}
