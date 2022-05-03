/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:09:59 by ddantas-          #+#    #+#             */
/*   Updated: 2022/04/04 15:10:12 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	n;

	n = 0;
	if (!s)
		return (0);
	while (s[n] != '\0')
		n++;
	return (n);
}

int	check_lines(char *string)
{
	char	*str;
	int		i;

	i = 0;
	if (!string)
		return (1);
	str = string;
	while (str[i++])
	{
		if (str[i] == '\n')
			return (0);
	}
	return (1);
}

char	*ft_strjoin(char *str, char *line)
{
	char	*join;
	int		n;
	int		i;

	join = malloc((ft_strlen(line) + ft_strlen(str) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	if (!line && str)
		return (str);
	n = -1;
	while (line[++n] != '\0')
		join[n] = line[n];
	i = -1;
	n = ft_strlen(line);
	while (str[++i] != '\0')
		join[n++] = str[i];
	join[n] = '\0';
	return (join);
}

char	*clean_str(char str[BUFFER_SIZE + 1])
{
	int	n;

	n = 0;
	if (!str)
		return (NULL);
	while (str[n] != '\0')
		str[n++] = '\0';
	return (str);
}
