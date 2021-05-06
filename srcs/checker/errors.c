/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:53:05 by ninieddu          #+#    #+#             */
/*   Updated: 2021/05/06 09:44:17 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/checker.h"

void	ft_crash(t_stack *a, t_stack *b, int *tmp, char **instr_tab)
{
	ft_putstr_fd("The program crash ! [Malloc error]\n", 1);
	free(a->stack);
	if (b->stack)
		free(b->stack);
	if (instr_tab)
		ft_tabdel(&instr_tab);
	if (tmp)
		free(tmp);
	exit(-1);
}

int		ft_is_error(char **av, int ac, int i)
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
			ft_putstr_fd("Error, invalid args in stack (need integer).\n", 2);
			return (-1);
		}
	}
	i = 0;
	while (av[++i])
	{
		if (ft_atoi_big(av[i]) > 2147483647
			|| ft_atoi_big(av[i]) < -2147483648 || ft_strlen(av[i]) > 19)
		{
			ft_putstr_fd("Error, invalid args in stack (args need to be ", 2);
			ft_putstr_fd("less than int max and sup than int min).\n", 2);
			return (-1);
		}
	}
	return (0);
}

void	ft_tabdel(char ***tab)
{
	int	i;

	if (!tab || !*tab)
		return ;
	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = 0;
}

void	ft_write_bn(char *s)
{
	if (s)
	{
		write(1, s, sizeof(char) * ft_strlen(s));
		write(1, "\n", 1);
	}
}

void	ft_is_writable(char *inst, t_stack *a, t_stack *b)
{
	if (ft_strcmp(inst, "pa") == 0 && b->size > 0)
		ft_write_bn(inst);
	if (ft_strcmp(inst, "pb") == 0 && a->size > 0)
		ft_write_bn(inst);
	if (ft_strcmp(inst, "ra") == 0 && a->size > 1)
		ft_write_bn(inst);
	if (ft_strcmp(inst, "rb") == 0 && b->size > 1)
		ft_write_bn(inst);
	if (ft_strcmp(inst, "pa") != 0 && ft_strcmp(inst, "pb") != 0 &&
	ft_strcmp(inst, "ra") != 0 && ft_strcmp(inst, "rb") != 0)
		ft_write_bn(inst);
}
