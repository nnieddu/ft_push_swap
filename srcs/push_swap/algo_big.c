/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:17:14 by ninieddu          #+#    #+#             */
/*   Updated: 2021/05/06 08:23:12 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int		ft_compute_pivot(t_stack *s, int size)
{
	int	i;
	int	j;
	int	total;

	i = -1;
	j = -1;
	total = 0;
	while (++j != size)
		total += s->stack[++i];
	return (total / size);
}

void	ft_opti_big(t_stack *a, t_stack *b)
{
	while (b->size != 0)
	{
		ft_is_bigest(b);
		if (b->size / 2 > b->pbigest)
			while (b->stack[0] != b->bigest)
				exec_instru("rb", a, b);
		else
			while (b->stack[0] != b->bigest)
				exec_instru("rrb", a, b);
		exec_instru("pa", a, b);
	}
}

void	sort(t_stack *a, t_stack *b, int size, int i)
{
	int	ra;
	int	pivot;

	ra = 0;
	pivot = ft_compute_pivot(a, size);
	while (i < size)
	{
		if (size % 2 != 0 && a->stack[0] < pivot)
			exec_instru("pb", a, b);
		else if (size % 2 == 0 && a->stack[0] <= pivot)
			exec_instru("pb", a, b);
		else
		{
			exec_instru("ra", a, b);
			ra++;
		}
		i++;
	}
	while (ra-- != 0 && a->flag == 1)
		exec_instru("rra", a, b);
	a->flag = 1;
	if (b->size <= 27)
		ft_opti_big(a, b);
}

void	ft_quicksort(t_stack *a, t_stack *b, int size, int i)
{
	if (size == 1)
	{
		exec_instru("ra", a, b);
		return ;
	}
	if (ft_is_sorted_num(a, size) == 0)
	{
		if (ft_is_sorted_num_rev(a) == 1)
		{
			while (i < size)
			{
				exec_instru("ra", a, b);
				i++;
			}
		}
		return ;
	}
	sort(a, b, size, 0);
	while (b->size != 0)
		exec_instru("pa", a, b);
	ft_quicksort(a, b, size / 2, 0);
	if (size % 2 != 0)
		size++;
	ft_quicksort(a, b, size / 2, 0);
}

void	ft_algo(t_stack *a, t_stack *b)
{
	a->flag = 0;
	ft_quicksort(a, b, a->size, 0);
	if (a->stack[0] > a->stack[1])
		exec_instru("ra", a, b);
}
