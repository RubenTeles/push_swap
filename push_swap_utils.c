/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:24:26 by rteles            #+#    #+#             */
/*   Updated: 2022/06/08 14:39:03 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_list **lst)
{
	t_list	*temp;

	*lst = ft_lstfirst(*lst);
	while ((*lst))
	{
		if ((*lst)->next != NULL)
			temp = (*lst)->next;
		else
			break ;
		free(*lst);
		if (temp != NULL)
			*lst = temp;
	}
	free(*lst);
}

void	ft_exit(int option)
{
	if (option == 0)
		ft_printf("\033[1;31mNothing\n\033[0m");
	else if (option == 1)
		ft_printf("\033[1;31mError\n\033[0m");
	exit(0);
}

void	ft_verification(char **str, int i)
{
	long	j;

	if (ft_strlen(str[i]) == 0)
		ft_exit(1);
	j = ft_atoi(str[i]);
	if (j > 2147483647 || j < -2147483648)
		ft_exit(1);
	if (ft_strlen(str[i]) == 1 && *str[i] == '-')
		ft_exit(1);
}

void	put_in_list(char **str, t_list **lst_a, t_list **lst_b, int len)
{
	int		i;
	t_list	*temp;

	(void)lst_b;
	if (!ft_str_s_str(str[0], "-1234567890"))
		ft_exit(1);
	ft_verification(str, 0);
	*lst_a = ft_lstnew(ft_atoi(str[0]));
	(*lst_a)->previus = 0;
	i = 0;
	while (str[++i])
	{
		if (!ft_str_s_str(str[i], "-1234567890"))
			ft_exit(1);
		ft_verification(str, i);
		(*lst_a)->next = ft_lstnew(ft_atoi(str[i]));
		temp = *lst_a;
		*lst_a = (*lst_a)->next;
		(*lst_a)->previus = temp;
	}
	*lst_a = ft_lstfirst(*lst_a);
	create_index(*lst_a, len, -1);
	(*lst_a)->begin = ft_lstfirst(*lst_a);
}
