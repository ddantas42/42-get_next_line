/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:41:18 by ddantas-          #+#    #+#             */
/*   Updated: 2022/05/23 16:41:30 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	int	n;

	n = 0;
	if (!s)
		return (0);
	while (s[n] != '\0' && s[n] != '\n')
		n++;
	return (n + (s[n] == '\n'));
}

void	clean_before_n(char *temp)
{
	int	n;
	int	i;

	n = 0;
	i = -1;
	while (temp[n] != '\0')
	{
		if (i >= 0)
			temp[i++] = temp[n];
		if (i == -1 && temp[n] == '\n')
			i = 0;
		temp[n++] = '\0';
	}
}

int	check_line(char *str)
{
	int	n;

	n = -1;
	while (str[++n])
	{
		if (str[n] == '\n')
		{
			clean_before_n(str);
			return (0);
		}
	}
	clean_before_n(str);
	return (1);
}

char	*ft_strjoin(char *line, char *temp)
{
	char	*join;
	int		n;
	int		i;

	join = malloc((ft_strlen(line) + ft_strlen(temp) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	n = 0;
	while (line && line[n])
	{
		join[n] = line[n];
		n++;
	}
	i = -1;
	while (temp[++i])
	{
		join[n++] = temp[i];
		if (temp[i] == '\n')
			break ;
	}
	join[n] = '\0';
	if (line)
		free(line);
	return (join);
}
