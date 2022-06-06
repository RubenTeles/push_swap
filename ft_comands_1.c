/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comands_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:21:36 by rteles            #+#    #+#             */
/*   Updated: 2022/06/06 18:28:37 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(t_list **lstx_1, int i)
{
	if (*lstx_1 == 0)
		return (0);
	ft_lst_sa(&(*lstx_1)->begin);
	if (i == 1)
		ft_printf("sa\n");
	return (1);
}

int	ft_sb(t_list **lstx_2, int i)
{
	if (*lstx_2 == 0)
		return (0);
	ft_lst_sa(&(*lstx_2)->begin);
	if (i == 1)
		ft_printf("sb\n");
	return (1);
}

int	ft_ss(t_list **lstx_1, t_list **lstx_2, int i)
{
	if (*lstx_1 == 0 || *lstx_2 == 0)
		return (0);
	ft_lst_sa(&(*lstx_1)->begin);
	ft_lst_sa(&(*lstx_2)->begin);
	if (i == 1)
		ft_printf("ss\n");
	return (1);
}

int	ft_pb(t_list **lstx_1, t_list **lstx_2, int i)
{
	if (*lstx_1 == 0)
		return (0);
	ft_lst_pa(lstx_1, lstx_2);
	if (i == 1)
		ft_printf("pb\n");
	return (1);
}

int	ft_pa(t_list **lstx_1, t_list **lstx_2, int i)
{
	if (*lstx_2 == 0)
		return (0);
	ft_lst_pa(lstx_2, lstx_1);
	if (i == 1)
		ft_printf("pa\n");
	return (1);
}
