/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:47:56 by rteles            #+#    #+#             */
/*   Updated: 2022/05/24 10:08:08 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//----------------- Logic for 3 Number's -----------------
void	logic_3(t_list **lst_a, t_list **lst_b, int *i)
{
	(void)lst_b;
	if ((*lst_a)->num > (*lst_a)->next->num)
	{
		if ((*lst_a)->num > (*lst_a)->next->next->num)
				*i += ft_ra(lst_a);
		else
			*i += ft_sa(lst_a);
	}
	else
	{
		if ((*lst_a)->num > (*lst_a)->next->next->num)
				*i += ft_rra(lst_a);
		else
			*i += ft_sa(lst_a);
	}
}
/*
//----------------- Logic for 5 Number's -----------------
void	logic_5(t_list **lst_a, t_list **lst_b, int *i)
{
	int	a_max_ra;
	int	a_max_rra;
	int	b_max_ra;
	int	b_max_rra;

	if ((*lst_a)->num > (*lst_a)->next->num)
	{
		if ((*lst_a)->num > (*lst_a)->next->next->num)
				*i += ft_ra(lst_a);
		else
			*i += ft_sa(lst_a);
	}
	else
	{
		if ((*lst_a)->num > (*lst_a)->next->next->num)
				*i += ft_rra(lst_a);
		else
			*i += ft_sa(lst_a);
	}
}
*/