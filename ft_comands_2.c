/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comands_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:21:36 by rteles            #+#    #+#             */
/*   Updated: 2022/05/17 23:37:25 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ra(t_list **lstx_1)
{
	ft_lst_ra(lstx_1);
	ft_printf("RA\n");
	return (1);
}

int	ft_rb(t_list **lstx_2)
{
	ft_lst_ra(lstx_2);
	ft_printf("RB\n");
	return (1);
}

int	ft_rr(t_list **lstx_1, t_list **lstx_2)
{
	ft_lst_ra(lstx_1);
	ft_lst_ra(lstx_2);
	ft_printf("RR\n");
	return (1);
}
