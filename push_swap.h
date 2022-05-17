/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 23:00:05 by rteles            #+#    #+#             */
/*   Updated: 2022/05/17 23:43:57 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*begin;
	int				num;
	struct s_list	*next;
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

//----- Verification Number ----- ///Falta ver se os numeros sao iguais
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
int		ft_pa(t_list **lstx_1, t_list **lstx_2);

int		ft_ra(t_list **lstx_1);
int		ft_rb(t_list **lstx_2);
int		ft_rr(t_list **lstx_1, t_list **lstx_2);

int		ft_rra(t_list **lstx_1);
int		ft_rrb(t_list **lstx_2);
int		ft_rrr(t_list **lstx_1, t_list **lstx_2);

#endif
