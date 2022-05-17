/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:10:16 by rteles            #+#    #+#             */
/*   Updated: 2022/05/17 10:25:06 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*head;

	if (*lst != NULL)
	{
		head = ft_lstlast(*lst);
		head->next = new;
	}
	else
		*lst = new;
}
