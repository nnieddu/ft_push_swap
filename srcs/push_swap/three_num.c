/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:08:25 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/21 11:43:51 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	ft_is_lowest(t_stack *a)
{
	int i;

	i = -1;
	a->lowest = a->stack[0];
	a->plowest = 0;
	while (++i < a->size)
	{
		if (a->stack[i] < a->lowest)
		{
			a->lowest = a->stack[i];
			a->plowest = i;
		}
	}
	i = -1;
	if (a->stack[0] == a->lowest)
	{
		a->lowest_n = a->stack[1];
		a->plowest_n = 1;
	}
	else
	{
		a->plowest_n = 0;
		a->lowest_n = a->stack[0];
	}
	while (++i < a->size)
	{
		if (a->stack[i] < a->lowest_n && a->stack[i] != a->lowest)
		{
			a->lowest_n = a->stack[i];
			a->plowest_n = i;
		}
	}
}

void	ft_is_bigest(t_stack *a)
{
	int i;

	i = -1;
	a->bigest = a->stack[0];
	a->pbigest = 0;
	while (++i < a->size)
	{
		if (a->stack[i] > a->bigest)
		{
			a->bigest = a->stack[i];
			a->pbigest = i;
		}
	}
	i = -1;
	if (a->stack[0] == a->bigest)
	{
		a->bigest_n = a->stack[1];
		a->pbigest_n = 1;
	}
	else
	{
		a->bigest_n = a->stack[0];
		a->pbigest_n = 1;
	}
	while (++i < a->size)
	{
		if (a->stack[i] > a->bigest_n && a->stack[i] != a->bigest)
		{
			a->bigest_n = a->stack[i];
			a->pbigest_n = i;
		}
	}
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