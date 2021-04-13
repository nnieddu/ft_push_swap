/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:04:39 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/13 13:25:18 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/checker.h"

void		ft_swap(int flag, t_stack *a, t_stack *b)
{
	int 	tmp;

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

void		ft_push(t_stack *a, t_stack *b)
{
	int		*tmp;
	int		i;

	i = 1;
	a->size--;
	b->size++;
	tmp = malloc(sizeof(int) * b->size);
	tmp[0] = a->stack[0];
	while (i < b->size)
	{
		tmp[i] = b->stack[i - 1];
		i++;
	}
	free(&b->stack);
	b->stack = tmp;
	i = 0;
	tmp = malloc(sizeof(int) * a->size);
	while (i < a->size)
	{
		tmp[i] = a->stack[i + 1];
		i++;
	}
	free(&a->stack);
	a->stack = tmp;
}

void		ft_rotate(int flag, t_stack *a, t_stack *b)
{
	int		*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(int) * a->size);
	tmp[a->size - 1] = a->stack[i];
	while (i < a->size - 1)
	{
		tmp[i] = a->stack[i + 1];
		i++;
	}
	free(&a->stack);
	a->stack = tmp;
	if (flag == 1)
		ft_rotate(0, b, NULL);
}

void		ft_reverse_rotate(int flag, t_stack *a, t_stack *b)
{
	int		*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(int) * a->size);
	tmp[i] = a->stack[a->size - 1];
	while (i < a->size - 1)
	{
		tmp[i + 1] = a->stack[i];
		i++;
	}
	free(&a->stack);
	a->stack = tmp;
	if (flag == 1)
		ft_reverse_rotate(0, b, NULL);
}
