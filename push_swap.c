/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:24:26 by rteles            #+#    #+#             */
/*   Updated: 2022/05/17 23:41:18 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(void)
{
	ft_printf("Erro!\n");
	exit(0);
}

void	show_list(t_list *lst_a, t_list *lst_b)
{
	ft_printf("  A  |  B  \n-----|-----\n");
	while (lst_a != NULL)
	{
		ft_printf("%i    ", lst_a->num);
		if (lst_b != NULL)
		{
			ft_printf("    %i", lst_b->num);
			lst_b = lst_b->next;
		}
		ft_printf("\n");
		lst_a = lst_a->next;
	}
}

void	put_in_list(char **str, t_list *lst_a, t_list *lst_b)
{
	int		i;
	t_list	*temp;

	if (!ft_str_s_str(str[0], "-123456789"))
		ft_exit();
	else
		lst_a->num = ft_atoi(str[0]);
	i = 0;
	temp = lst_a;
	while (str[++i])
	{
		if (!ft_str_s_str(str[i], "-123456789"))
			ft_exit();
		temp->next = ft_lstnew(ft_atoi(str[i]));
		temp = temp->next;
	}
	lst_b = NULL;
	show_list(lst_a, lst_b);
}

int	main(int argc, char **argv)
{
	t_list	lst_a;
	t_list	lst_b;
	char	**argv2;
	int		len;

	if (argc < 2)
		ft_exit();
	else if (argc == 2)
	{
		argv2 = ft_split(argv[1], ' ');
		len = 0;
		while (argv2[len])
			len++;
		put_in_list(argv2, &lst_a, &lst_b);
	}
	else
		put_in_list(&argv[1], &lst_a, &lst_b);
	lst_a.begin = &lst_a;
	lst_b.begin = NULL;
	ft_lst_pa(&lst_a.begin, &lst_b.begin);
	show_list(lst_a.begin, lst_b.begin);
	return (0);
}

/*
gcc -g libft/ft_lstnew.c libft/ft_lstlast.c push_swap.c push_swap_utils.c libft/ft_atoi.c libft/ft_itoa.c libft/ft_str_s_str.c libft/ft_split.c
./a.out 1 5 12 2 3 1 4 123 123455612

	ft_lst_pa(&lst_a.begin, &lst_b.begin);
	show_list(lst_a.begin, lst_b.begin);


*/