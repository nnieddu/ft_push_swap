/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:17:14 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/28 19:20:44 by ninieddu         ###   ########lyon.fr   */
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

int	ft_compute_pivot(t_stack *s, int size)
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

void	ft_algo_s(t_stack *a, t_stack *b)
{
	int i = a->size - 1;
	{
		while (i > 0 && ft_is_sorted_num_rev(a) == 1)
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

void	ft_algo_s_opti(t_stack *a, t_stack *b)
{
	exec_instru("pb", a, b);
	exec_instru("pb", a, b);
	if (b->stack[0] < b->stack[1])
		exec_instru("sb", a, b);
	int flag = 0;
	int rota = 0;
	int i = a->size / 2;
	while (i > 0)
	{
		while (a->stack[0] < b->stack[0]) // && a->stack[0] > b->stack[b->size])
		{
			ft_is_lowest(b);
			if (a->stack[0] < b->lowest)
			{
				exec_instru("pb", a, b);
				exec_instru("rb", a, b);
				flag = 1;
				break;
			}
			exec_instru("rb", a, b);
			rota++;
		}
		if (flag == 0)
			exec_instru("pb", a, b);
		while (rota > 0)
		{
			exec_instru("rrb", a, b);
			rota--;
		}
		flag = 0;
		i--;
	}
	i = a->size;
	rota = 0;
	while (i > 0)
	{
		ft_is_lowest(b);
		ft_is_bigest(b);
		while (a->stack[0] < b->stack[0] && a->stack[0] > b->lowest && a->stack[0] > b->bigest)
		{
			exec_instru("rb", a, b);
			rota++;
		}
		exec_instru("pb", a, b);
		if (b->stack[0] < b->lowest)
			exec_instru("rb", a, b);
		i--;
	}
	while (b->stack[0] != b->bigest)
		exec_instru("rb", a, b);
	exec_instru("pa", a, b);
	ft_is_bigest(b);
	while (b->stack[0] != b->bigest)
		exec_instru("rb", a, b);
	
	i = b->size;
	while (i > 0)
	{
		exec_instru("pa", a, b); 
		i--;
	}
}


void	ft_algo(t_stack *a, t_stack *b)
{
	ft_algo_s_opti(a, b);
}


// int	ft_compute_pivot_test(t_stack *s, int size)
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
// 	if (ft_is_sorted_num(a, size) == 0)
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