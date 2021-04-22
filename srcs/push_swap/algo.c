/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:17:14 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/22 20:43:32 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	partition(t_stack *a, t_stack *b, int beg, int end)
{
	int	left;
	int	right;
	int	temp; 
	int	temploc; 
	int	loc;
	int	flag;

	loc = left = beg;
	right = end;
	flag = 0;
	while(flag != 1)
	{
		while ((a->stack[loc] <= a->stack[right]) && (loc != right))
			right--;
		if (loc == right)
			flag = 1;
		else if (a->stack[loc] > a->stack[right])
		{
			temp = right;
			temploc = loc;
			while (temploc > 0)
			{
				exec_instru("ra", a, b);
				a->nrotate++;
				temploc--;
			}
			exec_instru("pb", a, b);
			while (a->nrotate > 0)
			{
				a->nrotate--;
				exec_instru("rra", a, b);
			}			
			a->npush++;
			while (temp - 1 > 0)
			{
				a->nrotate++;
				temp--;
				exec_instru("ra", a, b);
			}
			exec_instru("pb", a, b);
			exec_instru("sb", a, b);
			exec_instru("pa", a, b);
			while (a->nrotate > 0)
			{
				a->nrotate--;
				exec_instru("rra", a, b);
			}
			temp = loc;
			while (temp > 0)
			{
				temp--;
				exec_instru("ra", a, b);
			}
			exec_instru("pa", a, b);
			temp = loc;
			while (temp > 0)
			{
				temp--;
				exec_instru("rra", a, b);
			}			
            loc = right; 
			a->nrotate = 0;
		}
		if (flag != 1)
		{
			while ((a->stack[loc] >= a->stack[left]) && (loc != left))
				left++;
			if(loc == left)
				flag = 1;
			else if(a->stack[loc] < a->stack[left])
			{
				temp = left;
				temploc = loc;
				while (temploc > 0)
				{
					exec_instru("ra", a, b);
					a->nrotate++;
					temploc--;
				}
				exec_instru("pb", a, b);
				while (a->nrotate > 0)
				{
					a->nrotate--;
					exec_instru("rra", a, b);
				}			
				a->npush++;
				while (temp - 1 > 0)
				{
					a->nrotate++;
					temp--;
					exec_instru("ra", a, b);
				}
				exec_instru("pb", a, b);
				exec_instru("sb", a, b);
				exec_instru("pa", a, b);
				while (a->nrotate > 0)
				{
					a->nrotate--;
					exec_instru("rra", a, b);
				}
				temp = loc;
				while (temp > 0)
				{
					temp--;
					exec_instru("ra", a, b);
				}
				exec_instru("pa", a, b);
				temp = loc;
				while (temp > 0)
				{
					temp--;
					exec_instru("rra", a, b);
				}			
				loc = left;
			}
		}
	}
	return loc;
}

void	quickSort(t_stack *a, t_stack *b, int beg, int end)
{
	int	loc;
	if (beg < end)
	{
		loc = partition(a, b, beg, end);
		quickSort(a, b, beg, loc - 1);
		quickSort(a, b, loc + 1, end);
	}
}


void	ft_algo(t_stack *a, t_stack *b)
{
	a->nrotate = 0;
	a->npush = 0;
	// int i;
	quickSort(a, b, 0, a->size - 1);
	// printf("\n The sorted array is: \n");
	// for(i=0;i<a->size;i++)
	// printf("%d ", a->stack[i]);
}