/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:33:00 by rteles            #+#    #+#             */
/*   Updated: 2022/05/17 10:35:33 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			s;
	long long	n;

	i = 0;
	s = 1;
	n = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		if (n * s > 2147483647)
			return (-1);
		else if (n * s < -2147483648)
			return (0);
		i++;
	}
	return (n * s);
}
