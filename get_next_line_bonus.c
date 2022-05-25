/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:40:34 by ddantas-          #+#    #+#             */
/*   Updated: 2022/05/23 16:40:46 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	temp[FOPEN_MAX][BUFFER_SIZE + 1];
	ssize_t		read_size;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	read_size = 1;
	line = NULL;
	while (read_size > 0)
	{
		if (temp[fd][0] == '\0')
			read_size = read(fd, temp[fd], BUFFER_SIZE);
		if (read_size > 0)
			line = ft_strjoin(line, temp[fd]);
		if (!check_line(temp[fd]))
			break ;
	}
	return (line);
}
