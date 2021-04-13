/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 08:46:28 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/13 13:18:18 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/checker.h"

void	exec_instr(char **inst, int i, t_stack *a, t_stack *b)
{
	while(inst[++i])
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

void	ft_stacks_maker(char **av, int ac, t_stack *a, t_stack *b)
{
	int			i;

	i = 0;
	a->stack = malloc(sizeof(int) * ac);
	b->stack = malloc(sizeof(int) * ac);
	a->size = ac - 1;
	b->size = 0;
	while (i < ac - 1)
	{
		a->stack[i] = ft_atoi(av[i + 1]);
		b->stack[i] = 0;
		i++;
	}
}

int		main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	char	*input = NULL;
	char	*instr_str = NULL;
	char	*instr_str_tmp = NULL;
	char	**instr_tab = NULL;

	if (ac < 2)
		return (0);
	if (ft_is_error(av, ac, 0) == -1)
		return (-1);
	if (ft_is_sorted(ac, av) == 1)
	{
		ft_stacks_maker(av, ac, &a, &b);
		while (1)
		{
			input = ft_get_input(0, NULL);
			if (input[0] == 0 && instr_str != NULL)
			{
				ft_strdel(input);
				instr_tab = ft_split(instr_str, ' ');
				ft_strdel(instr_str);
				exec_instr(instr_tab, -1, &a, &b);
				ft_tabdel(&instr_tab);
				break;
			}
			else
			{
				if (ft_is_instruction(input) == 0)
				{
					instr_str_tmp = &*instr_str;
					instr_str = ft_strjoin_cust(instr_str_tmp, input);
					ft_strdel(instr_str_tmp);
				}
			}
			ft_strdel(input);
		}
		if (ft_is_sorted_num(a) == 1)
			ft_putstr_fd("KO\n", 1);
		else
			ft_putstr_fd("OK\n", 1);
		free(a.stack);
		free(b.stack);
	}
	return (0);
}
