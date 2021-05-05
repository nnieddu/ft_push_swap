/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:53:47 by ninieddu          #+#    #+#             */
/*   Updated: 2021/05/05 18:08:37 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/checker.h"

void			ft_get_input_next(char **line, char buff[2])
{
	if (*line)
	{
		if (*buff == '\n')
			*line = ft_strjoin(*line, "\0");
		else
			*line = ft_strjoin(*line, buff);
	}
	else
	{
		if (*buff == '\n')
			*line = ft_strjoin("", "\0");
		else
			*line = ft_strjoin("", buff);
	}
}

char			*ft_get_input(int fd, char *line, char *tmp)
{
	char		buff[2];

	buff[1] = 0;
	while (1)
	{
		tmp = line;
		if (read(fd, buff, 1) == 0)
		{
			if (!tmp)
				break ;
			continue ;
		}
		ft_get_input_next(&line, buff);
		if (line == NULL)
		{
			free(tmp);
			free(line);
			return (NULL);
		}
		if (tmp)
			free(tmp);
		if (*buff == '\n')
			break ;
	}
	return (line);
}

long long		ft_atoi_big(const char *str)
{
	long long	big;
	char		sign;

	big = 0;
	sign = '+';
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			sign = *str;
		}
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		big = big * 10 + (*str - 48);
		str++;
	}
	if (sign == '-')
		return (-big);
	return (big);
}

char			*ft_strjoin_cust(char *s1, char const *s2)
{
	char		*dest;
	int			i;

	i = 0;
	dest = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (dest == NULL)
		return (NULL);
	if (s1)
		while (*s1)
			dest[i++] = *s1++;
	while (*s2)
		dest[i++] = *s2++;
	dest[i] = ' ';
	dest[i + 1] = '\0';
	return (dest);
}

void			exec_instr(char **inst, int i, t_stack *a, t_stack *b)
{
	while (inst[++i])
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
