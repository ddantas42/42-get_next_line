/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:17:23 by ddantas-          #+#    #+#             */
/*   Updated: 2022/05/17 18:13:06 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	temp[BUFFER_SIZE + 1];
	ssize_t		read_size;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= FOPEN_MAX)
		return (NULL);
	read_size = 1;
	line = NULL;
	while (read_size > 0)
	{
		if (temp[0] == '\0')
			read_size = read(fd, temp, BUFFER_SIZE);
		if (read_size > 0)
			line = ft_strjoin(line, temp);
		if(!check_line(temp))
			break ;
	}
	return (line);
}
