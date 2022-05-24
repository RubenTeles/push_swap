/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:00:05 by rteles            #+#    #+#             */
/*   Updated: 2022/05/24 10:38:28 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include <unistd.h>

typedef struct s_swap
{
	int	selected;
	int	max_ra;
	int	max_rra;
	int	x;
}	t_swap;

typedef struct s_list
{
	struct s_list	*begin;
	int				index;
	int				num;
	struct s_list	*next;
	struct s_list	*previus;
}	t_list;

t_list	*ft_lstnew(int num);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_atoi(const char *str);
char	*ft_itoa(int n);

char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *string);

//---- Utils Funcions -----

void	show_list(t_list **lst_a, t_list **lst_b);
void	create_index(t_list *lst_a, int len, int i);
void	ft_exit(void);

//----- Verification Number -----
int		ft_str_s_str(const char *s1, const char *s2);

//----- Comands Function -----
void	ft_lst_sa(t_list **lstx);
void	ft_lst_pa(t_list **lstx_1, t_list **lstx_2);
void	ft_lst_ra(t_list **lstx);
void	ft_lst_rra(t_list **lstx);

//------ Comands ------
int		ft_sa(t_list **lstx_1);
int		ft_sb(t_list **lstx_2);
int		ft_ss(t_list **lstx_1, t_list **lstx_2);

int		ft_pa(t_list **lstx_1, t_list **lstx_2);
int		ft_pb(t_list **lstx_1, t_list **lstx_2);

int		ft_ra(t_list **lstx_1);
int		ft_rb(t_list **lstx_2);
int		ft_rr(t_list **lstx_1, t_list **lstx_2);

int		ft_rra(t_list **lstx_1);
int		ft_rrb(t_list **lstx_2);
int		ft_rrr(t_list **lstx_1, t_list **lstx_2);

//------ Logic ------
int		verific_list(t_list *lst_a, t_list *lst_b, int len);
void	logic_3(t_list **lst_a, t_list **lst_b, int *i);

#endif
