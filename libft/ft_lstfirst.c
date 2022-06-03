/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:47:58 by rteles            #+#    #+#             */
/*   Updated: 2022/06/03 20:31:54 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstfirst(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->previus != NULL)
		lst = lst->previus;
	return (lst);
}
