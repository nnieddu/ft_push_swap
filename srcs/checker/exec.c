/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 18:04:39 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/12 22:48:34 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/checker.h"

void	ft_swap(int flag, int ac, t_stack *a, t_stack *b)
{
	if ((flag == 0 || flag == 2) && ac > 2) // ac need to be modified by size of the stack
	{
		printf("Swap in a");
	}
	if ((flag == 1 || flag == 2) && ac > 2)
	{
		printf("Swap in b");
	}	
}

// void	ft_push(int flag, t_stack *a, t_stack *b)
// {
	
// }

// void	ft_rotate(int flag, t_stack *a, t_stack *b)
// {
	
// }