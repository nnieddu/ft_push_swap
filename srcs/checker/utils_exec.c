/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:48:42 by ninieddu          #+#    #+#             */
/*   Updated: 2021/05/05 18:08:19 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int		ft_is_sorted(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (i < ac)
	{
		while (j < ac && ft_atoi(av[i]) < ft_atoi(av[j]))
			j++;
		if (j == ac)
		{
			i++;
			j = i + 1;
		}
		else
			break ;
	}
	if (j < ac)
		return (1);
	return (0);
}

int		ft_is_sorted_num_rev(t_stack *a)
{
	int	i;

	if (a->size <= 1)
		return (0);
	i = a->size - 1;
	while (i > 0)
	{
		if (a->stack[i] > a->stack[i - 1])
			return (1);
		i--;
	}
	return (0);
}

int		ft_is_sorted_num(t_stack *a, int size)
{
	int	i;

	i = 0;
	if (size == 1)
		return (0);
	while (i < size - 1)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int		ft_is_number(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((av[i] < '0' || av[i] > '9') && av[i] != '-' && av[i] != '+')
			return (-1);
		i++;
	}
	return (0);
}

int		ft_is_duplicate(char **av, int ac, int i, int j)
{
	while (i < ac)
	{
		while (j < ac && ft_atoi(av[i]) != ft_atoi(av[j]))
			j++;
		if (j == ac)
		{
			i++;
			j = i + 1;
		}
		else
			break ;
	}
	if (j < ac)
		return (-1);
	return (0);
}
