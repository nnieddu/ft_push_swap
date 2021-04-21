/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 08:48:48 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/21 16:02:25 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

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
	ft_is_bigest(a);
	ft_is_lowest(a);	
}

int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;

	if (ac < 2)
		return (0);	
	if (ft_is_error(av, ac, 0) == -1)
		return (-1);
	if (ac == 3 && ft_atoi(av[1]) > ft_atoi(av[2]))
		exec_instru("sa", &a, NULL);
	else if (ft_is_sorted(ac, av) == 1)
	{
		ft_stacks_maker(av, ac, &a, &b);		
		if (ac == 4)
			ft_three_num(&a);
		if (ac == 6)
			ft_five_num(&a, &b);
		if (ac != 4 && ac != 6)
			ft_algo(&a, &b);
		free(a.stack);
		free(b.stack);
	}
	return (0);
}