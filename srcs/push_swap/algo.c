/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:17:14 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/27 13:04:42 by ninieddu         ###   ########lyon.fr   */
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

int		ft_is_sort_rev(t_stack *a)
{
	int	i;

	if (a->size < 2)
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
			while (a->stack[0] != a->lowest)
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
	ft_algo_s(a, b);
	// int i;
	// dprintf(2, "\nThe sorted array is: \n");
	// for(i=0;i<a->size;i++)
	// dprintf(2, "%d ", a->stack[i]);	
	// if (ft_is_sorted_num(*a) == 1)
	// 	ft_putstr_fd("KO\n", 2);
	// else
	// 	ft_putstr_fd("OK\n", 2);	
}





// int	ft_compute_pivot(t_stack *s, int size)
// {
// 	int	i;
// 	int	j;
// 	int	total;

// 	i = -1;
// 	j = -1;
// 	total = 0;
// 	while (++j != size)
// 		total += s->stack[++i];
// 	return (total / size);
// }

// int		ft_is_chunk_sort(t_stack *a, int size)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	if (a->size == 1)
// 		return (0);
// 	while (j < size)
// 	{
// 		if (a->stack[i] > a->stack[i + 1])
// 			return (1);
// 		j++;
// 		i++;
// 	}
// 	return (0);
// }

// void	sort(t_stack *a, t_stack *b, int size)
// {
// 	int i;
// 	int	ra;
// 	int	pivot;

// 	i = 0;
// 	ra = 0;
// 	pivot = ft_compute_pivot(a, size);
// 	while (i < size)
// 	{
// 		if (size % 2 != 0 && a->stack[0] < pivot)
// 			exec_instru("pb", a, b);
// 		else if (size % 2 == 0 && a->stack[0] <= pivot)
// 			exec_instru("pb", a, b);
// 		else
// 		{
// 			exec_instru("ra", a, b);
// 			ra++;
// 		}
// 		i++;
// 	}	
// 	while (ra-- != 0)
// 		exec_instru("rra", a, b);
// 	while (b->size != 0)
// 		exec_instru("pa", a, b);
// }

// void	quicksort(t_stack *a, t_stack *b, int size)
// {
// 	int	i;

// 	i = 0;
// 	if (size == 1)
// 	{
// 		exec_instru("ra", a, b);
// 		return ;
// 	}
// 	if (ft_is_chunk_sort(a, size) == 0)
// 	{
// 		if (ft_is_sorted_num_rev(a) == 1)
// 		{
// 			while (i < size)
// 			{
// 				exec_instru("ra", a, b);
// 				i++;
// 			}
// 		}
// 		return ;
// 	}
// 	sort(a, b, size);
// 	quicksort(a, b, size / 2);
// 	if (size % 2 != 0)
// 		size++;
// 	quicksort(a, b, size / 2);
// }

// void	ft_algo(t_stack *a, t_stack *b)
// {
// 	quicksort(a, b, a->size);
// 	if (a->stack[0] > a->stack[1])
// 		exec_instru("ra", a, b);
// }