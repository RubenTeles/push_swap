/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comands_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 23:21:36 by rteles            #+#    #+#             */
/*   Updated: 2022/05/17 23:31:45 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(t_list **lstx_1)
{
	ft_lst_sa(lstx_1);
	ft_printf("SA\n");
	return (1);
}

int	ft_sb(t_list **lstx_2)
{
	ft_lst_sa(lstx_2);
	ft_printf("SB\n");
	return (1);
}

int	ft_ss(t_list **lstx_1, t_list **lstx_2)
{
	ft_lst_sa(lstx_1);
	ft_lst_sa(lstx_2);
	ft_printf("SS\n");
	return (1);
}

int	ft_pa(t_list **lstx_1, t_list **lstx_2)
{
	ft_lst_pa(lstx_1, lstx_2);
	ft_printf("PA\n");
	return (1);
}

int	ft_pa(t_list **lstx_1, t_list **lstx_2)
{
	ft_lst_pa(lstx_2, lstx_1);
	ft_printf("PB\n");
	return (1);
}
