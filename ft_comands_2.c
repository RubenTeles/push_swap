/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comands_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:21:36 by rteles            #+#    #+#             */
/*   Updated: 2022/05/24 15:39:17 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(t_list **lstx_1, int i)
{
	ft_lst_ra(lstx_1);
	if (i == 1)
		ft_printf("ra\n");
	return (1);
}

int	ft_rb(t_list **lstx_2, int i)
{
	ft_lst_ra(lstx_2);
	if (i == 1)
		ft_printf("rb\n");
	return (1);
}

int	ft_rr(t_list **lstx_1, t_list **lstx_2, int i)
{
	ft_lst_ra(lstx_1);
	ft_lst_ra(lstx_2);
	if (i == 1)
		ft_printf("rr\n");
	return (1);
}
