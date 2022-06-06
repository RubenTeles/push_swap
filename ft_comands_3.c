/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comands_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:21:36 by rteles            #+#    #+#             */
/*   Updated: 2022/06/06 18:26:55 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rra(t_list **lstx_1, int i)
{
	if (*lstx_1 == 0)
		return (0);
	ft_lst_rra(&(*lstx_1)->begin);
	if (i == 1)
		ft_printf("rra\n");
	return (1);
}

int	ft_rrb(t_list **lstx_2, int i)
{
	if (*lstx_2 == 0)
		return (0);
	ft_lst_rra(&(*lstx_2)->begin);
	if (i == 1)
		ft_printf("rrb\n");
	return (1);
}

int	ft_rrr(t_list **lstx_1, t_list **lstx_2, int i)
{
	if (*lstx_1 == 0 || *lstx_2 == 0)
		return (0);
	ft_lst_rra(&(*lstx_1)->begin);
	ft_lst_rra(&(*lstx_2)->begin);
	if (i == 1)
		ft_printf("rrr\n");
	return (1);
}
