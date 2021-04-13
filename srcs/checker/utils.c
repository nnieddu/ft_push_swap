/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ninieddu <ninieddu@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 12:53:47 by ninieddu          #+#    #+#             */
/*   Updated: 2021/04/13 13:14:25 by ninieddu         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/checker.h"

char *ft_get_input(int fd, char *line)
{
	char buff[2];
	char *tmp;

	buff[1] = 0;
	while (1)
	{
		tmp = line;
		if (read(fd, buff, 1) == 0)
		{
			if (!tmp)
				break;
			continue;
		}
		if (!(line = ft_strjoin((line ? line : "\0"),
								(*buff == '\n' ? "\0" : buff))))
			return (NULL);
		if (tmp)
			free(tmp);
		if (*buff == '\n')
			break;
	}
	return (line);
}

long long		ft_atoi_big(const char *str)
{
	long long	big;
	char	sign;

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
	return (sign == '-' ? -big: big);
}

void ft_strdel(char *str)
{
	if (str == NULL)
		return;
	free(str);
	str = NULL;
}

char	*ft_strjoin_cust(char *s1, char const *s2)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 2))))
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
