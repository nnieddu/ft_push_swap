/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:44:59 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/28 11:27:38 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../srcs/ext/libft/libft.h"
# include "../srcs/ext/ft_printf/ft_printf.h"
# include "../srcs/ext/ft_get_next_line/get_next_line.h"


# define QUARTER frame->quarter
# define MEDIAN frame->median
# define THREE_Q frame->three_quarters
# define BIGGEST frame->biggest
# define BIG_ROTATE frame->big_rotate
# define BIG_RROTATE frame->big_rrotate
# define BIG_FLAG frame->big_flag
# define SMALLEST frame->smallest
# define SMALL_ROTATE frame->small_rotate
# define SMALL_RROTATE frame->small_rrotate
# define SMALL_FLAG frame->small_flag

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

	int			hold_first;
	int			hold_second;
}				t_stack;

long long	ft_atoi_big(const char *str);
char		*ft_get_input(int fd, char *line);
int			ft_is_error(char **av, int ac, int i);
int			ft_is_sorted(int ac, char **av);
char		*ft_strjoin_cust(char *s1, char const *s2);
void		ft_tabdel(char ***tab);
int			ft_is_sorted_num(t_stack *a, int size);
void		exec_instr(char **inst, int i, t_stack *a, t_stack *b);
void		ft_swap(int flag, t_stack *a, t_stack *b);
void		ft_push(t_stack *a, t_stack *b);
void		ft_rotate(int flag, t_stack *a, t_stack *b);
void		ft_reverse_rotate(int flag, t_stack *a, t_stack *b);

#endif
