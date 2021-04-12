/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:44:59 by cmalfroy          #+#    #+#             */
/*   Updated: 2021/04/12 17:54:24 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "../srcs/ext/libft/libft.h"
#include "../srcs/ext/ft_printf/ft_printf.h"
#include "../srcs/ext/ft_get_next_line/get_next_line.h"

typedef struct s_stack
{
	int			*stack;
}				t_stack;

long long	ft_atoi_big(const char *str);
void 		ft_strdel(char *str);
char 		*ft_get_input(int fd, char *line);
int 		ft_is_error(char **av, int ac, int i);
int 		ft_is_sorted(int ac, char **av, int i, int j);
int			ft_is_instruction(char *input);
char		*ft_strjoin_cust(char *s1, char const *s2);
void		ft_tabdel(char ***tab);
int 		ft_is_sorted_num(int ac, t_stack a, int i, int j);
void		ft_tabdel_int(int **tab);

#endif
