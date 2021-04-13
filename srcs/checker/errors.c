/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:53:05 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/13 16:24:41 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/checker.h"

int	ft_is_sorted(int ac, char **av)
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

int 	ft_is_sorted_num(t_stack a)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < a.size)
	{
		while (j < a.size && a.stack[i] < a.stack[j])
			j++;
		if (j == a.size)
		{
			i++;
			j = i + 1;
		}
		else
			break ;
	}
	if (j < a.size)
		return (1);
	return (0);
}

int 	ft_is_number(char *av)
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

int 	ft_is_duplicate(char **av, int ac, int i, int j)
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

int 	ft_is_error(char **av, int ac, int i)
{
	if (ft_is_duplicate(av, ac, 1, 2) == -1)
	{
		ft_putstr_fd("Error, duplicate number in stack args.\n", 2);
		return (-1);
	}
	while (av[++i])
	{
		if (ft_is_number(av[i]) == -1)
		{
			ft_putstr_fd("Error, invalid args in stack (only integer)", 2);
			return (-1);
		}
	}
	i = 0;
	while (av[++i])
	{
		if (ft_atoi_big(av[i]) > 2147483647
			|| ft_atoi_big(av[i]) < -2147483648)
		{
			ft_putstr_fd("Error, invalid args in stack (args need to be ", 2);
			ft_putstr_fd("less than int max and sup than int min).\n", 2);
			return (-1);
		}	
	}
	return (0);
}
