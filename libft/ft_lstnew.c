/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:01:31 by rteles            #+#    #+#             */
/*   Updated: 2022/05/17 18:51:18 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int num)
{
	t_list	*head;

	head = (t_list *)malloc(sizeof(t_list));
	if (head == NULL)
		return (0);
	head->num = num;
	head->next = NULL;
	return (head);
}
