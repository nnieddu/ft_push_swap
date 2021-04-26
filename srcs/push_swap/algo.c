/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:17:14 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/26 17:42:28 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

// void	ft_algo_b(t_stack *a, t_stack *b)
// {
// 	int i = a->size - 1;
// 	while (i > 0)
// 	{	
// 		while (a->stack[0] != a->bigest)
// 		{
// 			if (a->pbigest <= a->size / 2)
// 				exec_instru("ra", a, b);
// 			else
// 				exec_instru("rra", a, b);
// 		}
// 		exec_instru("pb", a, b); 
// 		i--;
// 		ft_is_bigest(a);
// 	}
// 	i = b->size;
// 	while (i > 0)
// 	{
// 		exec_instru("ra", a, b);
// 		exec_instru("pa", a, b); 
// 		i--;
// 	}
// 	exec_instru("ra", a, b);
// }

// int		ft_is_best_move(t_stack *a)
// {
// 	int i;
// 	int x;
// 	int y;

// 	i = 0;
// 	x = 0;
// 	while (i < a->size - 1)
// 	{
// 		if (a->stack[i] < a->stack[i + 1])
// 			x++;
// 		i++;
// 	}
// 	i = 0;
// 	while (i < a->size - 1)
// 	{
// 		if (a->stack[i] > a->stack[i + 1])
// 			y++;
// 		i++;
// 	}
// 	if (x > y)
// 		return (0);
// 	else
// 		return (1);
// }

// int		ft_is_sort_rev(t_stack *a)
// {
// 	int	i;

// 	if (a->size <= 1)
// 		return (0);
// 	i = 0;
// 	while (i < a->size - 1)
// 	{
// 		if (a->stack[i] > a->stack[i + 1])
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// void	ft_algo_s(t_stack *a, t_stack *b)
// {
// 	int i = a->size - 1;
// 	{
// 		while (i > 0 && ft_is_sort_rev(a) == 1)
// 		{
// 			while (a->stack[0] != a->lowest && ft_is_sort_rev(a) == 1)
// 			{
// 				if (a->plowest_n == 0 && a->plowest == 1)
// 					exec_instru("sa", a, b);
// 				else if (a->plowest <= a->size / 2)
// 					exec_instru("ra", a, b);
// 				else
// 					exec_instru("rra", a, b);
// 			}
// 			if (ft_is_sort_rev(a) == 1)
// 				exec_instru("pb", a, b); 
// 			i--;
// 			ft_is_lowest(a);
// 		}
// 	}
// 	i = b->size;
// 	while (i > 0)
// 	{
// 		exec_instru("pa", a, b); 
// 		i--;
// 	}	
// }

// void	ft_algo(t_stack *a, t_stack *b)
// {
	
// 	// ft_algo_c(a, b);
// 	if (ft_is_best_move(a) == 1)
// 		ft_algo_s(a, b);
// 	else
// 		ft_algo_b(a, b);
// 	// int i;
// 	// dprintf(2, "\nThe sorted array is: \n");
// 	// for(i=0;i<a->size;i++)
// 	// dprintf(2, "%d ", a->stack[i]);	
// 	// if (ft_is_sorted_num(*a) == 1)
// 	// 	ft_putstr_fd("KO\n", 2);
// 	// else
// 	// 	ft_putstr_fd("OK\n", 2);	
// }



// int	getTop(t_stack *s)
// {
// 	int	i;
// 	int	ret;

// 	i = 1;
// 	ret = s->stack[0];
// 	while (i < s->size)
// 	{
// 		if (ret < s->stack[i])
// 			ret = s->stack[i];
// 		i++;
// 	}
// 	return (ret);
// }

// int	get_top_index(t_stack *s, int top)
// {
// 	int	i;

// 	i = s->size - 1;
// 	while (i >= 0)
// 	{
// 		if (s->stack[i] == top)
// 			return (i);
// 		i--;
// 	}
// 	return (i);
// }

// void	handleMinCase(t_stack *a, t_stack *b)
// {
// 	int	top;

// 	while (b->size != 0)
// 	{
// 		top = getTop(b);
// 		if (b->size / 2 > get_top_index(b, top))
// 			while (b->stack[b->size - 1] != top)
// 				reverse_rotate_b(b, WRITE);
// 		else
// 			while (b->stack[b->size - 1] != top)
// 				rotate_b(b, WRITE);
// 		push_a(a, b);
// 	}
// }





int	chunkPivot(t_stack *s, int size)
{
	int	ret;
	int	i;
	int	c;

	i = 0;
	ret = 0;
	c = 0;
	while (c != size)
	{
		ret += s->stack[i];
		i++;
		c++;
	}
	return (ret / size);
}

int	hash(t_stack *a, t_stack *b, int size, int pivot)
{
	int	i;
	int	rotation;

	i = 0;
	rotation = 0;
	while (i < size)
	{
		if (size % 2 != 0 && a->stack[0] < pivot)
			exec_instru("pb", a, b);
		else if (size % 2 == 0 && a->stack[0] <= pivot)
			exec_instru("pb", a, b);
		else
		{
			exec_instru("ra", a, b);
			rotation++;
		}
		i++;
	}
	return (rotation);
}

void	split(t_stack *a, t_stack *b, int size)
{
	int	pivot;
	int	rotation;

	rotation = 0;
	pivot = chunkPivot(a, size);
	rotation = hash(a, b, size, pivot);
	while (rotation != 0 && a->first_lap == 1)
	{
		exec_instru("rra", a, b);
		rotation--;
	}
	a->first_lap = 1;
	// if (b->size <= 27)
	// 	handleMinCase(a, b);
	while (b->size != 0)
	{
		exec_instru("pa", a, b);
	}
}

int		checking_sort(t_stack *s)
{
	int	i;

	if (s->size <= 1)
		return (0);
	i = s->size - 1;
	while (i > 0)
	{
		if (s->stack[i] > s->stack[i - 1])
			return (1);
		i--;
	}
	return (0);
}

int		chunkStackisSort(t_stack *a, int size)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	if (a->size == 1)
		return (0);
	while (c < size)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (1);
		c++;
		i++;
	}
	return (0);
}

void	quicksort(t_stack *a, t_stack *b, int size)
{
	int	i;

	i = 0;
	if (size == 1)
	{
		exec_instru("ra", a, b);
		return ;
	}
	if (chunkStackisSort(a, size) == 0)
	{
		if (checking_sort(a) == 1)
		{
			while (i < size)
			{
				exec_instru("ra", a, b);
				i++;
			}
		}
		return ;
	}
	split(a, b, size);
	quicksort(a, b, size / 2);
	if (size % 2 != 0)
		size++;
	quicksort(a, b, size / 2);
}


void	ft_algo(t_stack *a, t_stack *b)
{
	a->first_lap = 0;
	quicksort(a, b, a->size);
	if (a->stack[0] > a->stack[1])
			exec_instru("ra", a, b);
	int i;
	dprintf(2, "\nThe sorted array is: \n");
	for(i=0;i<a->size;i++)
	dprintf(2, "%d ", a->stack[i]);	
	if (ft_is_sorted_num(*a) == 1)
		ft_putstr_fd("KO\n", 2);
	else
		ft_putstr_fd("OK\n", 2);
}