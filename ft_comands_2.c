/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comands_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:21:36 by rteles            #+#    #+#             */
/*   Updated: 2022/06/06 18:24:54 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(t_list **lstx_1, int i)
{
	if (*lstx_1 == 0)
		return (0);
	ft_lst_ra(&(*lstx_1)->begin);
	if (i == 1)
		ft_printf("ra\n");
	return (1);
}

int	ft_rb(t_list **lstx_2, int i)
{
	if (*lstx_2 == 0)
		return (0);
	ft_lst_ra(&(*lstx_2)->begin);
	if (i == 1)
		ft_printf("rb\n");
	return (1);
}

int	ft_rr(t_list **lstx_1, t_list **lstx_2, int i)
{
	if (*lstx_1 == 0 || *lstx_2 == 0)
		return (0);
	ft_lst_ra(&(*lstx_1)->begin);
	ft_lst_ra(&(*lstx_2)->begin);
	if (i == 1)
		ft_printf("rr\n");
	return (1);
}
