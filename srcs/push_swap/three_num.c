/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:08:25 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/20 19:55:46 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	ft_is_lowest_n(t_stack *a)
{
	int i;
	int	poz;

	i = -1;
	poz = 0;	
	i = -1;
	poz = 0;
	a->smallest_n = a->stack[1];
	while (++i < a->size)
	{
		if (a->stack[i] < a->smallest_n && a->stack[i] != a->smallest)
		{
			a->smallest_n = a->stack[i];
			poz = i;
		}
	}
	return (poz);
}

int	ft_is_lowest(t_stack *a)
{
	int i;
	int	poz;

	i = -1;
	poz = 0;
	a->smallest = a->stack[0];
	while (++i < a->size)
	{
		if (a->stack[i] < a->smallest)
		{
			a->smallest = a->stack[i];
			poz = i;
		}
	}
	return (poz);
}

int	ft_is_bigest_n(t_stack *a)
{
	int i;
	int	poz;

	i = -1;
	poz = 0;
	a->bigest_n = a->stack[1];
	while (++i < a->size)
	{
		if (a->stack[i] < a->bigest_n && a->stack[i] != a->bigest_n)
		{
			a->bigest_n = a->stack[i];
			poz = i;
		}
	}
	return (poz);
}

int	ft_is_bigest(t_stack *a)
{
	int i;
	int	poz;

	i = -1;
	poz = 0;
	a->bigest = a->stack[0];
	while (++i < a->size)
	{
		if (a->stack[i] < a->bigest)
		{
			a->bigest = a->stack[i];
			poz = i;
		}
	}
	return (poz);
}

void	exec_instru(char *inst, t_stack *a, t_stack *b)
{
	if (ft_strcmp(inst, "sa") == 0)
		ft_swap(0, a, b);
	if (ft_strcmp(inst, "sb") == 0)
		ft_swap(1, a, b);
	if (ft_strcmp(inst, "ss") == 0)
		ft_swap(2, a, b);
	if (ft_strcmp(inst, "pa") == 0 && b->size > 0)
		ft_push(b, a);
	if (ft_strcmp(inst, "pb") == 0 && a->size > 0)
		ft_push(a, b);
	if (ft_strcmp(inst, "ra") == 0 && a->size > 1)
		ft_rotate(0, a, NULL);
	if (ft_strcmp(inst, "rb") == 0 && b->size > 1)
		ft_rotate(0, b, NULL);
	if (ft_strcmp(inst, "rr") == 0)
		ft_rotate(1, a, b);
	if (ft_strcmp(inst, "rra") == 0)
		ft_reverse_rotate(0, a, NULL);
	if (ft_strcmp(inst, "rrb") == 0)
		ft_reverse_rotate(0, b, NULL);
	if (ft_strcmp(inst, "rrr") == 0)
		ft_reverse_rotate(1, a, b);
	ft_putstr_fd(inst, 1);
	ft_putstr_fd("\n", 1);
	
}

void	ft_five_num(t_stack *a, t_stack *b)
{
	(void)b;
	// while (a->stack[0] != ft_is_lowest(a))
	dprintf(2, "[%d]\n", ft_is_lowest(a));
	dprintf(2, "[%d]\n", ft_is_lowest_n(a));
	dprintf(2, "[%d]\n", a->smallest);
	dprintf(2, "[%d]\n", a->smallest_n);
	// while (a->stack[0] != 4)
	// 	exec_instru("ra", a, b);
	// exec_instru("pb", a, b);
	// while (a->stack[0] != 5)
	// 	exec_instru("ra", a, b);
	// exec_instru("pb", a, b);
	// ft_three_num(a);
	// exec_instru("pa", a, b);
	// exec_instru("pa", a, b);
	// exec_instru("ra", a, b);
	// exec_instru("ra", a, b);
	dprintf(2, "a = %d %d %d %d %d\n", a->stack[0], a->stack[1], a->stack[2], a->stack[3], a->stack[4]);
	// dprintf(2, "b = %d %d %d %d %d %d %d\n", b->stack[0], b->stack[1], b->stack[2], b->stack[3], b->stack[4], b->stack[5], b->stack[6]);
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