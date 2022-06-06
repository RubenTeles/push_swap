/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:24:26 by rteles            #+#    #+#             */
/*   Updated: 2022/06/06 18:51:21 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	**argv2;

	lst_a = 0;
	lst_b = 0;
	if (argc < 2)
		ft_exit(1);
	else if (argc == 2)
	{
		argv2 = ft_split(argv[1], ' ');
		argc = 0;
		while (argv2[argc])
			argc++;
		put_in_list(argv2, &lst_a, &lst_b, argc);
	}
	else
	{
		argc--;
		put_in_list(&argv[1], &lst_a, &lst_b, argc);
	}
	logic(&lst_a, &lst_b, argc);
	ft_free(&lst_a);
	ft_free(&lst_b);
	return (0);
}

//	system("leaks a.out");
/*	//
./a.out 1 5 12 2 3 1 4 123 123455612
show_list(&lst_a.begin, &lst_b.begin);
	ft_lst_pa(&lst_a.begin, &lst_b.begin);
	show_list(lst_a.begin, lst_b.begin);
scanf("%s");.


	*/