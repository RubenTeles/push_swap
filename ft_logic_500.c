/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_logic_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles <rteles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:47:56 by rteles            #+#    #+#             */
/*   Updated: 2022/06/01 21:06:28 by rteles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///void	chosen_index_500(t_range *range, int len)
///{
///	static int		c = 2;
///	static int		i = -1;
///	int				aux;
///	int				div;
///
///	i++;
///	range->len = len - 6;
///	div = range->len / c;
///	aux = range->len - div;
///	if (aux > range->len)
///		aux = range->len;
///	if (i > aux)
///		c *= 2;
///	div = range->len / c;
///	aux = range->len - div;
///	if (aux > range->len)
///		aux = range->len;
///	range->max = aux;
///	range->c = aux - i;
///	aux = c / 2;
///	range->min = range->max - div;
///	range->dif = range->max - range->min;
///	//ft_printf("\n\n Min:%i Max:%i Range:%i\n" ,range->min, range->max, range->dif);//(len / 200);
///}

////t_swap	index_list_position_500(t_list **lst, int min, int max)
////{
////	t_swap	l_a;
////	int		size;
////	t_list	*temp;
////	int		i;
////
////	i = 0;
////	temp = *lst;
////	size = ft_lstsize(temp);
////	while (1)
////	{
////		if (temp->index >= min && temp->index <= max)
////		{
////			l_a.index = temp->index;
////			l_a.max_ra = i;
////			l_a.max_rra = 2147483647;
////			l_a.selected = 1;
////			break ;
////		}
////		temp = temp->next;
////		i++;
////	}
////	return (l_a);
////}

//----------------- Logic for 500 Number's -----------------
///////void	logic_500(t_list **lst_a, t_list **lst_b, int len, int *i)
///////{
///////	t_range			range;
///////	t_s_swap		var;
///////
///////	chosen_index_plus(&range, len);
///////	var.a = index_list_position_500(lst_a, range.min, range.max);
///////	if (ft_lstsize(*lst_b) >= 2)
///////	{
///////		var.b = index_small_position(lst_b, var.a.index);
///////		if (var.b.max_ra <= var.b.max_rra)
///////		{
///////			if (var.a.max_ra <= var.b.max_ra)
///////				logic_while_rr(lst_a, lst_b, &var, i);
///////		}
///////	}
///////	logic_100_1(lst_a, lst_b, &var.a, i);
///////}

//void	logic_500(t_list **lst_a, t_list **lst_b, int len, int *i)
//{
//	t_range			range;
//	t_s_swap		var;
//
//	chosen_index_500(&range, len);
//	var.a = index_list_position(lst_a, range.min, range.max);
//	//ft_printf("\nMax: %i Min: %i Index: %i\n", range.max, range.min, var.a.index);
//	if (ft_lstsize(*lst_b) >= 2 && ft_lstsize(*lst_a) > ft_lstsize(*lst_b))
//	{
//		var.b = index_small_position(lst_b, var.a.index);
//		if (var.b.max_ra <= var.b.max_rra)
//		{
//			if (var.a.max_ra <= var.b.max_ra)
//				logic_while_rr(lst_a, lst_b, &var, i);
//			/*else
//			{
//				while (--var.b.max_ra >= 0)
//					*i = ft_rb(lst_b, 1);
//			}*/
//		}
//		else
//		{
//			if (var.a.max_rra <= var.b.max_rra)
//				logic_while_rrr(lst_a, lst_b, &var, i);
//			/*else
//			{
//				while (--var.b.max_rra >= 0)
//					*i = ft_rrb(lst_b, 1);
//			}*/
//		}
//	}
//	//if (ft_lstsize(*lst_b) >= 2)
//	//{
//	//	var.b = index_small_position(lst_b, var.a.index);
//	//	if (var.b.selected == 1 && var.a.selected == 1 && var.a.x >= var.b.x)
//	//		logic_while_rr(lst_a, lst_b, &var, i);
//	//	else if (var.b.selected == 0 && var.a.selected == 0
//	//		&& var.a.x >= var.b.x)
//	//		logic_while_rrr(lst_a, lst_b, &var, i);
//	//}
//	logic_100_1(lst_a, lst_b, &var.a, i);
//}

//////////////////void	logic_500_b_1(t_list **lst_a, t_list **lst_b, t_swap *var_a, int *i)
//////////////////{
//////////////////	if (var_a->selected == 0)
//////////////////	{
//////////////////		while (var_a->max_rra > 0)
//////////////////		{
//////////////////			*i += ft_rrb(lst_a, 1);
//////////////////			var_a->max_rra--;
//////////////////		}
//////////////////		*i += ft_pa(lst_a, lst_b, 1);
//////////////////	}
//////////////////	else
//////////////////	{
//////////////////		while (var_a->max_ra > 0)
//////////////////		{
//////////////////			*i += ft_rb(lst_a, 1);
//////////////////			var_a->max_ra--;
//////////////////		}
//////////////////		*i += ft_pa(lst_a, lst_b, 1);
//////////////////	}
//////////////////}

/*void	chosen_index_b_500(t_range *range, int len)
{
	static int		c = 2;
	static int		i = -1;
	int				aux;
	int				div;

	i++;
	range->len = len - 6;
	aux = range->len - div;
	if (aux > range->len)
		aux = range->len;
	if (i > aux)
		c *= 2;
	aux = range->len - div;
	if (aux > range->len)
		aux = range->len;
	range->max = aux;
	range->c = aux - i;
	aux = c / 2;
	range->min = range->max - div;
	range->dif = range->max - range->min;
	//ft_printf("\n\n Min:%i Max:%i Range:%i\n" ,range->min, range->max, range->dif);//(len / 200);
}*/

////////////void	logic_500_b(t_list **lst_a, t_list **lst_b, int len, int *i)
////////////{
////////////	t_range			range;
////////////	t_s_swap		var;
////////////
////////////	chosen_index_500(&range, len);
////////////	var.b = index_list_position(lst_b, range.min, range.max);
////////////	if (ft_lstsize(*lst_a) >= 2)
////////////	{
////////////		var.a = index_small_position(lst_a, var.a.index);
////////////		if (var.b.selected == 1 && var.a.selected == 1 && var.b.x >= var.a.x)
////////////			logic_while_rr(lst_a, lst_b, &var, i);
////////////		else if (var.b.selected == 0 && var.a.selected == 0
////////////			&& var.a.x >= var.b.x)
////////////			logic_while_rrr(lst_a, lst_b, &var, i);
////////////	}
////////////	logic_500_b_1(lst_b, lst_a, &var.b, i);
////////////}
