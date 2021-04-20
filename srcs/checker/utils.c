/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:53:47 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/19 11:18:24 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/checker.h"

void	ft_get_input_next(char **line, char buff[2])
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

char	*ft_get_input(int fd, char *line)
{
	char	buff[2];
	char	*tmp;

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
			return (NULL);
		if (tmp)
			free(tmp);
		if (*buff == '\n')
			break ;
	}
	return (line);
}

long long	ft_atoi_big(const char *str)
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
	if (sign == '-' )
		return (-big);
	return (big);
}

char	*ft_strjoin_cust(char *s1, char const *s2)
{
	char	*dest;
	int		i;

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

void	ft_tabdel(char ***tab)
{
	int		i;

	if (!tab || !*tab)
		return ;
	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = 0;
}
