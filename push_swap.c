/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:24:26 by rteles            #+#    #+#             */
/*   Updated: 2022/05/23 18:40:13 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(void)
{
	ft_printf("Error\n");
	exit(0);
}

void	show_list(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *lst_a;
	temp2 = *lst_b;
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

void	put_in_list(char **str, t_list *lst_a, t_list *lst_b)
{
	int		i;
	t_list	*temp;

	if (!ft_str_s_str(str[0], "-1234567890"))
		ft_exit();
	else
		lst_a->num = ft_atoi(str[0]);
	i = 0;
	temp = lst_a;
	while (str[++i])
	{
		if (!ft_str_s_str(str[i], "-1234567890"))
			ft_exit();
		temp->next = ft_lstnew(ft_atoi(str[i]));
		temp = temp->next;
	}
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
		put_in_list(argv2, &lst_a, &lst_b);
	}
	else
		put_in_list(&argv[1], &lst_a, &lst_b);
	lst_a.begin = &lst_a;
	lst_b.begin = NULL;
	verific_list(&lst_a, &lst_b, argc);
	return (0);
}

/*
	//show_list(&lst_a, &lst_b);
./a.out 1 5 12 2 3 1 4 123 123455612

	ft_lst_pa(&lst_a.begin, &lst_b.begin);
	show_list(lst_a.begin, lst_b.begin);*/