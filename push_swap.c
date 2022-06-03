/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:24:26 by rteles            #+#    #+#             */
/*   Updated: 2022/06/03 19:59:36 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_list *lst)
{
	t_list	*temp;
	int		i;

	while (lst->previus)
		lst = lst->previus;
	i = ft_lstsize(lst);
	while (--i >= 0)
	{
		if (lst->next != NULL)
			temp = lst->next;
		free(lst);
		if (temp != NULL)
			lst = temp;
		else
			lst = NULL;
	}
}

void	ft_exit(void)
{
	ft_printf("Error\n");
	exit(0);
}

void	put_in_list(char **str, t_list *lst_a, t_list *lst_b, int len)
{
	int		i;
	t_list	*temp1;
	t_list	*temp2;

	if (!ft_str_s_str(str[0], "-1234567890"))
		ft_exit();
	else
		lst_a->num = ft_atoi(str[0]);
	lst_a->previus = 0;
	i = 0;
	temp1 = lst_a;
	while (str[++i])
	{
		if (!ft_str_s_str(str[i], "-1234567890"))
			ft_exit();
		temp1->next = ft_lstnew(ft_atoi(str[i]));
		temp2 = temp1;
		temp1 = temp1->next;
		temp1->previus = temp2;
	}
	create_index(lst_a, len, -1);
	lst_b = NULL;
}

int	main(int argc, char **argv)
{
	t_list	lst_a;
	t_list	lst_b;
	char	**argv2;

	if (argc < 2)
		ft_exit();
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
	lst_a.begin = &lst_a;
	lst_b.begin = NULL;
	logic(&lst_a, &lst_b, argc);
	ft_free(&lst_a);
	ft_free(&lst_b);
	return (0);
}

/*	//
./a.out 1 5 12 2 3 1 4 123 123455612
show_list(&lst_a.begin, &lst_b.begin);
	ft_lst_pa(&lst_a.begin, &lst_b.begin);
	show_list(lst_a.begin, lst_b.begin);
scanf("%s");.


	*/