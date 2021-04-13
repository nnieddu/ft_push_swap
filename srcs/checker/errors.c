/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:53:05 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/12 22:03:46 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/checker.h"

int ft_is_sorted(int ac, char **av, int i, int j)
{
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
			break;
	}
	if (j < ac)
		return (1);
	return (0);
}

int ft_is_sorted_num(int ac, t_stack a, int i, int j)
{
	while (i < ac)
	{
		while (j < ac && a.stack[i] < a.stack[j])
			j++;
		if (j == ac)
		{
			i++;
			j = i + 1;
		}
		else
			break;
	}
	if (j < ac)
		return (1);
	return (0);
}

int ft_is_number(char *av)
{
	int i;

	i = 0;
	while (av[i])
	{
		if ((av[i] < '0' || av[i] > '9' || av[i] == ' ') && av[i] != '-') // can be improve
			return (-1);
		i++;
	}
	return (0);
}

int ft_is_duplicate(char **av, int ac, int i, int j)
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
			break;
	}
	if (j < ac)
		return (-1);
	return (0);
}

int ft_is_error(char **av, int ac, int i)
{
	if (ft_is_duplicate(av, ac, 1, 2) == -1)
	{
		ft_putstr_fd("Error, duplicate number in stack args.\n", 2);
		return (-1);
	}
	while (av[++i])
		if (ft_is_number(av[i]) == -1)
		{
			ft_putstr_fd("Error, invalid args in stack (only integer in int min and max range allowed).\n", 2);
			return (-1);
		}
	i = 0;
	while (av[++i])
	{
		if (ft_atoi_big(av[i]) > 2147483647 || ft_atoi_big(av[i]) < -2147483648)
		{
			ft_putstr_fd("Error, invalid args in stack (args need to be less than int max and sup than int min).\n", 2); // can be improv to manage bigbig
			return (-1);
		}	
	}
	return (0);
}

int		ft_is_instruction(char *input)
{
	if (ft_strcmp(input, "sa") == 0 || ft_strcmp(input, "sb") == 0 || 
	ft_strcmp(input, "ss") == 0 || ft_strcmp(input, "pa") == 0
	|| ft_strcmp(input, "pb") == 0 || ft_strcmp(input, "ra") == 0 || 
	ft_strcmp(input, "rb") == 0 || ft_strcmp(input, "rr") == 0
	|| ft_strcmp(input, "rra") == 0 || ft_strcmp(input, "rrb") == 0 || 
	ft_strcmp(input, "rrr") == 0)
		return (0);
	ft_putstr_fd("Error, invalid instruction (don't exist or not correctly formatted).\n", 2);
	return (-1);
}
