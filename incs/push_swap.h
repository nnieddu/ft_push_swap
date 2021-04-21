/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 08:48:42 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/21 11:45:23 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../srcs/ext/ft_printf/ft_printf.h"
# include "../srcs/ext/libft/libft.h"
# include "../incs/checker.h"

void    ft_three_num(t_stack *a);
void	ft_five_num(t_stack *a, t_stack *b);
void	exec_instru(char *inst, t_stack *a, t_stack *b);
void	ft_is_bigest(t_stack *a);
void	ft_is_lowest(t_stack *a);

#endif
