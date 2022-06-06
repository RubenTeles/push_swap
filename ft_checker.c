/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:31:44 by rteles            #+#    #+#             */
/*   Updated: 2022/06/06 15:53:10 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_list(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = (*lst_a)->begin;
	if (*lst_b != 0)
		temp2 = (*lst_b)->begin;
	else
		temp2 = 0;
	ft_printf("  A  |  B  \n-----|-----\n");
	while (temp1 != NULL || temp2 != NULL)
	{
		if (temp1 != NULL)
			ft_printf("%i    ", temp1->num);
		else
			ft_printf("     ");
		if (temp2 != NULL)
		{
			ft_printf("    %i", temp2->num);
			temp2 = temp2->next;
		}
		ft_printf("\n");
		if (temp1 != NULL)
			temp1 = temp1->next;
	}
}

/*int	main()
{
	read()
}*/