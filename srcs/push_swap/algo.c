/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:17:14 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/25 14:39:02 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	ft_algo_b(t_stack *a, t_stack *b)
{
	int i = a->size - 1;
	while (i > 0)
	{	
		while (a->stack[0] != a->bigest)
		{
			if (a->pbigest <= a->size / 2)
				exec_instru("ra", a, b);
			else
				exec_instru("rra", a, b);
		}
		exec_instru("pb", a, b); 
		i--;
		ft_is_bigest(a);
	}
	i = b->size;
	while (i > 0)
	{
		exec_instru("ra", a, b);
		exec_instru("pa", a, b); 
		i--;
	}
	exec_instru("ra", a, b);
}

int		ft_is_best_move(t_stack *a)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	while (i < a->size - 1)
	{
		if (a->stack[i] < a->stack[i + 1])
			x++;
		i++;
	}
	i = 0;
	while (i < a->size - 1)
	{
		if (a->stack[i] > a->stack[i + 1])
			y++;
		i++;
	}
	if (x > y)
		return (0);
	else
		return (1);
}

int		ft_is_sort_rev(t_stack *a)
{
	int	i;

	if (a->size <= 1)
		return (0);
	i = 0;
	while (i < a->size - 1)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	ft_algo_s(t_stack *a, t_stack *b)
{
	int i = a->size - 1;
	{
		while (i > 0 && ft_is_sort_rev(a) == 1)
		{
			while (a->stack[0] != a->lowest && ft_is_sort_rev(a) == 1)
			{
				if (a->plowest_n == 0 && a->plowest == 1)
					exec_instru("sa", a, b);
				else if (a->plowest <= a->size / 2)
					exec_instru("ra", a, b);
				else
					exec_instru("rra", a, b);
			}
			if (ft_is_sort_rev(a) == 1)
				exec_instru("pb", a, b); 
			i--;
			ft_is_lowest(a);
		}
	}
	i = b->size;
	while (i > 0)
	{
		exec_instru("pa", a, b); 
		i--;
	}	
}

void	ft_algo(t_stack *a, t_stack *b)
{
	
	// ft_algo_c(a, b);
	if (ft_is_best_move(a) == 1)
		ft_algo_s(a, b);
	else
		ft_algo_b(a, b);
	// int i;
	// dprintf(2, "\nThe sorted array is: \n");
	// for(i=0;i<a->size;i++)
	// dprintf(2, "%d ", a->stack[i]);	
	// if (ft_is_sorted_num(*a) == 1)
	// 	ft_putstr_fd("KO\n", 2);
	// else
	// 	ft_putstr_fd("OK\n", 2);	
}

