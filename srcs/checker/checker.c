/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 08:46:28 by ninieddu          #+#    #+#             */
/*   Updated: 2021/05/04 15:26:32 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/checker.h"

int	ft_is_instruction(char *input)
{
	if (ft_strcmp(input, "sa") == 0 || ft_strcmp(input, "sb") == 0
		|| ft_strcmp(input, "ss") == 0 || ft_strcmp(input, "pa") == 0
		|| ft_strcmp(input, "pb") == 0 || ft_strcmp(input, "ra") == 0
		|| ft_strcmp(input, "rb") == 0 || ft_strcmp(input, "rr") == 0
		|| ft_strcmp(input, "rra") == 0 || ft_strcmp(input, "rrb") == 0
		|| ft_strcmp(input, "rrr") == 0)
		return (0);
	ft_putstr_fd("Error, invalid instruction (don't exist or not ", 2);
	ft_putstr_fd("correctly formatted).\n", 2);
	return (-1);
}

void	ft_stacks_maker(char **av, int ac, t_stack *a, t_stack *b)
{
	int			i;

	i = 0;
	a->stack = malloc(sizeof(int) * ac);
	if (a->stack == NULL)
		ft_crash(a, NULL, NULL, NULL);
	b->stack = malloc(sizeof(int) * ac);
	if (b->stack == NULL)
		ft_crash(a, b, NULL, NULL);
	a->size = ac - 1;
	b->size = 0;
	while (i < ac - 1)
	{
		a->stack[i] = ft_atoi(av[i + 1]);
		b->stack[i] = 0;
		i++;
	}
}

int		ft_join_instrs(char **input, char **instr_str_tmp, char **instr_str)
{
	if (ft_is_instruction(*input) == 0)
	{
		*instr_str_tmp = &**instr_str;
		*instr_str = ft_strjoin_cust(*instr_str_tmp, *input);
		ft_strdel(*instr_str_tmp);
		if (instr_str == NULL)
			return (-1);
	}
	return (0);
}

void	ft_exec_loop(t_stack *a, t_stack *b, char *instr_str)
{
	char		*input;
	char		*instr_str_tmp;
	char		**instr_tab;

	while ((input = ft_get_input(0, NULL)))
	{
		if (ft_join_instrs(&input, &instr_str_tmp, &instr_str) == -1)
		{
			ft_strdel(input);
			ft_strdel(instr_str);
			ft_crash(a, b, NULL, NULL);
		}
		ft_strdel(input);
	}
	ft_strdel(input);
	instr_tab = ft_split(instr_str, ' ');
	ft_strdel(instr_str);
	if (instr_tab == NULL)
		ft_crash(a, b, NULL, instr_tab);
	exec_instr(instr_tab, -1, a, b);
	ft_tabdel(&instr_tab);
}

int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;

	if (ac < 2)
		return (0);
	if (ft_is_error(av, ac, 0) == -1)
		return (-1);
	if (ft_is_sorted(ac, av) == 1)
	{
		ft_stacks_maker(av, ac, &a, &b);
		ft_exec_loop(&a, &b, NULL);
		if (ft_is_sorted_num(&a, a.size) == 1)
			ft_putstr_fd("KO\n", 1);
		else
			ft_putstr_fd("OK\n", 1);
		free(a.stack);
		free(b.stack);
	}
	return (0);
}
