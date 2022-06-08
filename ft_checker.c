/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:31:44 by rteles            #+#    #+#             */
/*   Updated: 2022/06/08 14:41:58 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_list(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = 0;
	temp2 = 0;
	if (*lst_a != 0)
		temp1 = (*lst_a)->begin;
	if (*lst_b != 0)
		temp2 = (*lst_b)->begin;
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

int	ft_option_command_2(char *str, int len, t_list **lst_a, t_list **lst_b)
{
	if (ft_strncmp(str, "\n", len) == 0)
		return (-1);
	else
	{
		ft_printf("\033[1;31mError\n\033[0m");
		ft_free(lst_a);
		ft_free(lst_b);
		exit(0);
	}
	return (0);
}

int	ft_option_command(char *str, int len, t_list **lst_a, t_list **lst_b)
{
	if (ft_strncmp(str, "sa\n", ft_strlen(str)) == 0)
		return (ft_sa(lst_a, 0));
	else if (ft_strncmp(str, "sb\n", len) == 0)
		return (ft_sb(lst_b, 0));
	else if (ft_strncmp(str, "ss\n", len) == 0)
		return (ft_ss(lst_a, lst_b, 0));
	else if (ft_strncmp(str, "pa\n", len) == 0)
		return (ft_pa(lst_a, lst_b, 0));
	else if (ft_strncmp(str, "pb\n", len) == 0)
		return (ft_pb(lst_a, lst_b, 0));
	else if (ft_strncmp(str, "rra\n", len) == 0)
		return (ft_rra(lst_a, 0));
	else if (ft_strncmp(str, "rrb\n", len) == 0)
		return (ft_rrb(lst_b, 0));
	else if (ft_strncmp(str, "rrr\n", len) == 0)
		return (ft_rrr(lst_a, lst_b, 0));
	else if (ft_strncmp(str, "ra\n", len) == 0)
		return (ft_ra(lst_a, 0));
	else if (ft_strncmp(str, "rb\n", len) == 0)
		return (ft_rb(lst_b, 0));
	else if (ft_strncmp(str, "rr\n", len) == 0)
		return (ft_rr(lst_a, lst_b, 0));
	else
		return (ft_option_command_2(str, len, lst_a, lst_b));
}

void	ft_checker(t_list **lst_a, t_list **lst_b)
{
	char	*str;
	int		len;
	int		i;
	int		count;

	i = 1;
	count = 0;
	while (i == 1)
	{
		str = get_next_line(0);
		len = ft_strlen(str);
		i = ft_option_command(str, i, lst_a, lst_b);
		if (i == -1)
			break ;
		count += i;
	}
	if (count == 0)
		ft_exit(0);
	else if ((*lst_a) != 0 && (*lst_b) == 0 && is_right((*lst_a)->begin) == 1)
		ft_printf("\033[0;32mOK\n\033[0m");
	else
		ft_printf("\033[1;31mKO\n\033[0m");
}

int	main(int argc, char **argv)
{	
	t_list	*lst_a;
	t_list	*lst_b;
	char	**argv2;

	lst_a = 0;
	lst_b = 0;
	if (argc < 2)
		ft_exit(0);
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
	ft_checker(&lst_a, &lst_b);
	ft_free(&lst_a);
	ft_free(&lst_b);
	return (0);
}
