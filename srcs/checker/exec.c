/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:04:39 by ninieddu          #+#    #+#             */
/*   Updated: 2021/05/01 11:27:19 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/checker.h"

void	ft_swap(int flag, t_stack *a, t_stack *b)
{
	int	tmp;

	if ((flag == 0 || flag == 2) && a->size > 1)
	{
		tmp = a->stack[0];
		a->stack[0] = a->stack[1];
		a->stack[1] = tmp;
	}
	if ((flag == 1 || flag == 2) && b->size > 1)
	{
		tmp = b->stack[0];
		b->stack[0] = b->stack[1];
		b->stack[1] = tmp;
	}
}

void	ft_push(t_stack *a, t_stack *b)
{
	int		*tmp;
	int		i;

	i = 1;
	a->size--;
	b->size++;
	tmp = malloc(sizeof(int) * b->size);
	if (tmp == NULL)
		ft_crash(a, b, tmp, NULL);
	tmp[0] = a->stack[0];
	while (i < b->size)
	{
		tmp[i] = b->stack[i - 1];
		i++;
	}
	free(b->stack);
	b->stack = tmp;
	i = 0;
	tmp = malloc(sizeof(int) * a->size);
	if (tmp == NULL)
		ft_crash(a, b, tmp, NULL);
	while (i < a->size)
	{
		tmp[i] = a->stack[i + 1];
		i++;
	}
	free(a->stack);
	a->stack = tmp;
}

void	ft_rotate(int flag, t_stack *a, t_stack *b)
{
	int		*tmp;
	int		i;

	if (a->size > 1)
	{
		i = 0;
		tmp = malloc(sizeof(int) * a->size);
		if (tmp == NULL)
			ft_crash(a, b, tmp, NULL);
		tmp[a->size - 1] = a->stack[i];
		while (i < a->size - 1)
		{
			tmp[i] = a->stack[i + 1];
			i++;
		}
		free(a->stack);
		a->stack = tmp;
	}
	if (flag == 1)
		ft_rotate(0, b, NULL);
}

void	ft_reverse_rotate(int flag, t_stack *a, t_stack *b)
{
	int		*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(int) * a->size);
	if (tmp == NULL)
		ft_crash(a, b, tmp, NULL);
	tmp[i] = a->stack[a->size - 1];
	while (i < a->size - 1)
	{
		tmp[i + 1] = a->stack[i];
		i++;
	}
	free(a->stack);
	a->stack = tmp;
	if (flag == 1)
		ft_reverse_rotate(0, b, NULL);
}

void	exec_instr(char **inst, int i, t_stack *a, t_stack *b)
{
	while (inst[++i])
	{
		if (ft_strcmp(inst[i], "sa") == 0)
			ft_swap(0, a, b);
		if (ft_strcmp(inst[i], "sb") == 0)
			ft_swap(1, a, b);
		if (ft_strcmp(inst[i], "ss") == 0)
			ft_swap(2, a, b);
		if (ft_strcmp(inst[i], "pa") == 0 && b->size > 0)
			ft_push(b, a);
		if (ft_strcmp(inst[i], "pb") == 0 && a->size > 0)
			ft_push(a, b);
		if (ft_strcmp(inst[i], "ra") == 0 && a->size > 1)
			ft_rotate(0, a, NULL);
		if (ft_strcmp(inst[i], "rb") == 0 && b->size > 1)
			ft_rotate(0, b, NULL);
		if (ft_strcmp(inst[i], "rr") == 0)
			ft_rotate(1, a, b);
		if (ft_strcmp(inst[i], "rra") == 0)
			ft_reverse_rotate(0, a, NULL);
		if (ft_strcmp(inst[i], "rrb") == 0)
			ft_reverse_rotate(0, b, NULL);
		if (ft_strcmp(inst[i], "rrr") == 0)
			ft_reverse_rotate(1, a, b);
	}
}
