/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:57:06 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/21 16:00:57 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void    ft_algo(t_stack *a, t_stack *b)
{
	int i = a->size;
	while(i > 1)
	{
		while (a->stack[0] != a->lowest)
			exec_instru("ra", a, b);
		exec_instru("pb", a, b); 
		i--;
		ft_is_lowest(a);
	}
	i = b->size;
	while (i > 0)
	{
		exec_instru("pa", a, b); 
		i--;
	}
}
