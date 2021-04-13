/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 08:46:28 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/12 22:40:42 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/checker.h"

void	exec_instr(char **inst, int i, t_stack *a, t_stack *b)
{
	int ac = i;
	i = -1;
	while(inst[++i])
	{
		if (ft_strcmp(inst[i], "sa") == 0)
			ft_swap(0, ac, a, b);
		if (ft_strcmp(inst[i], "sb") == 0)
			ft_swap(1, ac, a, b);
		if (ft_strcmp(inst[i], "ss") == 0)
			ft_swap(2, ac, a, b);
		// if (ft_strcmp(inst[i], "pa") == 0)
		// 	ft_push(0, &a, &b);
		// if (ft_strcmp(inst[i], "pb") == 0)
		// 	ft_push(1, &a, &b);
		// if (ft_strcmp(inst[i], "ra") == 0)
		// 	ft_rotate(0, &a, &b);
		// if (ft_strcmp(inst[i], "rb") == 0)
		// 	ft_rotate(1, &a, &b);	
		// if (ft_strcmp(inst[i], "rr") == 0)
		// 	ft_rotate(2, &a, &b);
		// if (ft_strcmp(inst[i], "rra") == 0)
		// 	ft_rotate(3, &a, &b);
		// if (ft_strcmp(inst[i], "rrb") == 0)
		// 	ft_rotate(4, &a, &b);
		// if (ft_strcmp(inst[i], "rrr") == 0)
		// 	ft_rotate(5, &a, &b);
	}
}

void	ft_stacks_maker(char **av, int ac, t_stack *a, t_stack *b)
{
	int			i;

	i = 1;
	a->stack = malloc(sizeof(int) * ac);
	b->stack = malloc(sizeof(int) * ac);
	while (i < ac)
	{
		a->stack[i] = ft_atoi(av[i]);
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
	if (ft_is_sorted(ac, av, 1, 2) == 1)
	{
		ft_stacks_maker(av, ac, &a, &b);
		while (1)
		{
			input = ft_get_input(0, NULL);
			if (input[0] == 0)
			{
				ft_strdel(input);
				instr_tab = ft_split(instr_str, ' ');
				ft_strdel(instr_str);
				exec_instr(instr_tab, ac, &a, &b); // ac / -1
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
		if (ft_is_sorted_num(ac, a, 1, 2) == 1)
			ft_putstr_fd("KO\n", 1);
		if (ft_is_sorted_num(ac, a, 1, 2) == 0)
			ft_putstr_fd("OK\n", 1);
		ft_tabdel_int(&a.stack);
		// ft_tabdel_int(&b.stack); // INVALID FREE
	}
	return (0);
}

//sa :swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
//sb :swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
//ss :sa and sb at the same time.
//pa :push a - take the first element at the top ofband put it at the top of a. Do nothing if b is empty.
//pb :push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
//ra :rotate a - shift up all elements of stackaby 1. The first element becomesthe last one.
//rb :rotate b - shift up all elements of stackbby 1. The first element becomesthe last one.
//rr :ra and rb at the same time.
//rra :reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
//rrb :reverse rotate b - shift down all elements of stack b by 1. The last elementbecomes the first one.
//rrr :rra and rrbat the same time