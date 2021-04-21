/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_or_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:08:25 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/21 15:31:54 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	ft_five_num(t_stack *a, t_stack *b)
{
	if (a->lowest_n == 3 || a->lowest == 3)
	{
		while (a->stack[0] != a->bigest_n)
			exec_instru("ra", a, b);
		exec_instru("pb", a, b);
		while (a->stack[0] != a->bigest)
			exec_instru("ra", a, b);
		exec_instru("pb", a, b);
		ft_three_num(a);
		exec_instru("pa", a, b);
		exec_instru("pa", a, b);
		exec_instru("ra", a, b);
		exec_instru("ra", a, b);
		return ;
	}
	while (a->stack[0] != a->lowest)
		exec_instru("ra", a, b);
	exec_instru("pb", a, b);
	while (a->stack[0] != a->lowest_n)
		exec_instru("ra", a, b);
	exec_instru("pb", a, b);
	ft_three_num(a);
	exec_instru("pa", a, b);
	exec_instru("pa", a, b);
}

void	ft_three_num(t_stack *a)
{
	if (a->stack[0] > a->stack[1] && a->stack[1] < a->stack[2]
	&& a->stack[0] < a->stack[2])
		exec_instru("sa", a, NULL);
	if (a->stack[0] > a->stack[1] && a->stack[1] > a->stack[2])
	{
		exec_instru("sa", a, NULL);
		exec_instru("rra", a, NULL);
	}
	if (a->stack[0] > a->stack[1])
		exec_instru("ra", a, NULL);
	if (a->stack[0] < a->stack[1] && a->stack[0] > a->stack[2])
		exec_instru("rra", a, NULL);

	if (a->stack[0] < a->stack[1] && a->stack[1] > a->stack[2])
	{
		exec_instru("sa", a, NULL);
		exec_instru("ra", a, NULL);
	}
}