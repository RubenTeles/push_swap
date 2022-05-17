/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_s_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:18:05 by rteles            #+#    #+#             */
/*   Updated: 2022/05/17 16:40:57 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_str_s_str(const char *s1, const char *s2)
{
	size_t	i;
	size_t	a;

	i = -1;
	if (!s1 || !s2)
		return (0);
	while (s1[++i])
	{
		a = -1;
		while (s2[++a])
		{
			if (s1[i] == s2[a])
				break ;
		}
		if (s1[i] == s2[a])
			continue ;
		return (0);
	}
	return (1);
}
