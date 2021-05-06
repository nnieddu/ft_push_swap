/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:17:14 by ninieddu          #+#    #+#             */
/*   Updated: 2021/05/06 10:57:11 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

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

void	ft_algo_s_end(t_stack *a, t_stack *b)
{
	int	i;

	i = b->size;
	while (i > 0)
	{
		exec_instru("pa", a, b);
		i--;
	}
}

void	ft_algo_s(t_stack *a, t_stack *b, int i)
{
	while (i > 0)
	{
		while (a->stack[0] != a->lowest && ft_is_sorted_num(a, a->size) == 1)
		{
			if (a->plowest_n == 0 && a->plowest == 1)
				exec_instru("sa", a, b);
			else if (a->plowest <= a->size / 2)
				exec_instru("ra", a, b);
			else
				exec_instru("rra", a, b);
		}
		exec_instru("pb", a, b);
		i--;
		ft_is_lowest(a);
		ft_is_bigest(a);
		if (a->size == 2 && a->stack[0] == a->bigest
			&& a->stack[1] == a->lowest)
		{
			exec_instru("sa", a, b);
			break ;
		}
		if (ft_is_sorted_num(a, a->size) == 0 && ft_is_sorted_num_rev(b) == 0)
			break ;
	}
	ft_algo_s_end(a, b);
}
