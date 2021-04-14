/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 08:48:48 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/14 11:37:06 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"
#include "../../incs/checker.h"

// char	*ft_swap_algo(int ac, char **av)
// {
//	char *instr;


//	return (instr);
// }

int	main(int ac, char **av)
{
	if (ft_is_error(av, ac, 0) == -1)
		return (-1);
	if (ac == 3 && ft_atoi(av[1]) > ft_atoi(av[2]))
		ft_putstr_fd("sa\n\n", 1);
	else
		ft_swap_algo(ac, av);
	return (0);
} 