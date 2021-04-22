/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:44:59 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/22 15:16:29 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../srcs/ext/libft/libft.h"
# include "../srcs/ext/ft_printf/ft_printf.h"
# include "../srcs/ext/ft_get_next_line/get_next_line.h"

typedef struct s_stack
{
	int			*stack;
	int			size;
	int			lowest;
	int			lowest_n;
	int			plowest;
	int			plowest_n;
	int			bigest;
	int			bigest_n;
	int			pbigest;
	int			pbigest_n;

	int			npush;
	int			nrotate;
}				t_stack;

long long	ft_atoi_big(const char *str);
char		*ft_get_input(int fd, char *line);
int			ft_is_error(char **av, int ac, int i);
int			ft_is_sorted(int ac, char **av);
char		*ft_strjoin_cust(char *s1, char const *s2);
void		ft_tabdel(char ***tab);
int			ft_is_sorted_num(t_stack a);
void		exec_instr(char **inst, int i, t_stack *a, t_stack *b);
void		ft_swap(int flag, t_stack *a, t_stack *b);
void		ft_push(t_stack *a, t_stack *b);
void		ft_rotate(int flag, t_stack *a, t_stack *b);
void		ft_reverse_rotate(int flag, t_stack *a, t_stack *b);

#endif
