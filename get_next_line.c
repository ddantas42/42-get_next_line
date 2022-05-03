/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:09:17 by ddantas-          #+#    #+#             */
/*   Updated: 2022/04/04 15:09:38 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*all_string(int fd, char *line)
{
	ssize_t read_size;
	char	str[BUFFER_SIZE + 1];
	int		n;

	n = 0;
	read_size = 1;
	while (check_lines(line) == 1)
	{
		read_size = read(fd, str, BUFFER_SIZE);
		str[BUFFER_SIZE] = '\0';
		n++;
		if (read_size == 0)
		{
			line = ft_strjoin(str, line);
			break ;
		}
		line = ft_strjoin(str, line);
		clean_str(str);
	}
	return (line);
}

char	*string_temp(char *line)
{
	char	*temp;
	int		n;
	int		i;

	n = 0;
	while (line[++n])
	{
		if (line[n] == '\n')
			break ;
	}
	i = 0;
	temp = malloc(((ft_strlen(line) - n + 1) * sizeof(char)));
	if (!temp)
		return (NULL);
	while (line[++n] != '\0')
		temp[i++] = line[n];
	temp[i] = '\0';
	return (temp);
}

char	*line_fix(char *line)
{
	char	*line_fix;
	int		n;
	int		i;

	n = 0;
	while (line[++n])
	{
		if (line[n] == '\n')
			break ;
	}
	line_fix = malloc((n + 1) * sizeof(char));
	if (!line_fix)
	{
		free(line_fix);
		return (NULL);
	}
	i = -1;
	while (++i < n + 1)
		line_fix[i] = line[i];
	line_fix[++i] = '\0';
	return (line_fix);
}	

char	*get_next_line(int fd)
{
	char		*line;
	static char	*temp;

	if (BUFFER_SIZE <= 0  || fd < 0 || fd > 1024)
		return (NULL);
	temp = read(fd, temp, BUFFER_SIZE);
	line = temp;
	line = all_string(fd, line);
	if (line[0] == 0)
	{
		free(line);
		return (NULL);
	}
	temp = string_temp(line);
	line = line_fix(line);
	return (line);
}
