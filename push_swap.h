/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:00:05 by rteles            #+#    #+#             */
/*   Updated: 2022/06/06 15:18:09 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include <unistd.h>

typedef struct s_range
{
	int	min;
	int	max;
	int	len;
	int	c;
	int	dif;
}	t_range;

typedef struct s_swap
{
	int	index;
	int	selected;
	int	max_ra;
	int	max_rra;
	int	x;
}	t_swap;

typedef struct s_s_swap
{
	t_swap	a;
	t_swap	b;
	int		dif_rr;
	int		dif_r;
	int		dif_rr_r;
	int		dif;
	int		select;
}	t_s_swap;

typedef struct s_list
{
	struct s_list	*begin;
	int				index;
	int				num;
	struct s_list	*next;
	struct s_list	*previus;
}	t_list;

t_list	*ft_lstnew(int num);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstfirst(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

long	ft_atoi(const char *str);
char	*ft_itoa(int n);

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *string);

//---- Utils Funcions -----

void	show_list(t_list **lst_a, t_list **lst_b);
void	create_index(t_list *lst_a, int len, int i);
void	ft_exit(void);
t_swap	index_list_position(t_list **lst, int min, int max);
void	index_descending(t_list *temp, t_swap *l, int min, int max);
void	index_position(t_swap *l, int index, int size, int i);
void	chosen_index_plus(t_range *range, int len);
void	chosen_index_min_5(t_range *range, t_list *lst);

//----- Verification Number -----
int		ft_str_s_str(const char *s1, const char *s2);

//----- Comands Function -----
void	ft_lst_sa(t_list **lstx);
void	ft_lst_pa(t_list **lstx_1, t_list **lstx_2);
void	ft_lst_ra(t_list **lstx);
void	ft_lst_rra(t_list **lstx);

//------ Comands ------
int		ft_sa(t_list **lstx_1, int i);
int		ft_sb(t_list **lstx_2, int i);
int		ft_ss(t_list **lstx_1, t_list **lstx_2, int i);

int		ft_pa(t_list **lstx_1, t_list **lstx_2, int i);
int		ft_pb(t_list **lstx_1, t_list **lstx_2, int i);

int		ft_ra(t_list **lstx_1, int i);
int		ft_rb(t_list **lstx_2, int i);
int		ft_rr(t_list **lstx_1, t_list **lstx_2, int i);

int		ft_rra(t_list **lstx_1, int i);
int		ft_rrb(t_list **lstx_2, int i);
int		ft_rrr(t_list **lstx_1, t_list **lstx_2, int i);

//------ Logic ------
int		logic(t_list **lst_a, t_list **lst_b, int len);
int		is_right(t_list *list_a);
void	logic_while_rrr(t_list **lst_a, t_list **lst_b, t_s_swap *var, int *i);
void	logic_while_rr(t_list **lst_a, t_list **lst_b, t_s_swap *var, int *i);

//------ Logic 3 ------//
void	logic_number_3(t_list **lst_a, t_list **lst_b, int *i);
void	logic_3(t_list **lst_a, t_list **lst_b, int *i);

//------ Logic 5 ------//
void	logic_number_5(t_list **lst_a, t_list **lst_b, int *i);
void	logic_5(t_list **lst_a, t_list **lst_b, int *i);

//------ Logic Exceptions ------//
void	logic_exceptions(t_list **lst_a, t_list **lst_b, int *i);
void	logic_5_2(t_list **lst_a, t_list **lst_b, int *i);

//------ Logic 100/500 ------//
void	logic_number_100_500(t_list **lst_a, t_list **lst_b, int len, int *i);
void	logic_500(t_list **lst_a, t_list **lst_b, int len, int *i);
void	logic_500_b(t_list **lst_a, t_list **lst_b, int len, int *i);
t_swap	index_list_position_500(t_list **lst, int min, int max);
void	index_small_position_a(t_list **lst_a, t_swap *swp_b, t_s_swap *l);
void	swap_postion(t_s_swap *l, t_swap *l_a, t_swap *l_b);

//------ Checker ------//
void	show_list(t_list **lst_a, t_list **lst_b);

#endif
