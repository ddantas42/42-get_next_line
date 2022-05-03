/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:14:57 by ddantas-          #+#    #+#             */
/*   Updated: 2022/04/07 17:15:01 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>


#define BUFFER_SIZE 997767

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
	return(join);
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

char	*all_string(int fd, char *line)
{
	ssize_t read_size;
	char	str[BUFFER_SIZE + 1];                   //    printf("Começa all_string\n");
	int		n;

	n = 0;
	read_size = 1;
	while (check_lines(line) == 1)
	{
		read_size = read(fd, str, BUFFER_SIZE);	//	printf("\nRead_size = '%zd'\n", read_size);
		str[BUFFER_SIZE] = '\0';
		n++;
		if (read_size == 0)
		{
			line = ft_strjoin(str, line);
			break ;
		}
		line = ft_strjoin(str, line);
		// printf("string = '%s'\n", line);
		clean_str(str);
	}
	printf("string All_string = '%s'\n", line);
	return (line);
}

static char	*string_temp(char *line)
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
	printf("String temp final = '%s'\n", temp);
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
	static char	*temp = "";

	printf("Começa get_next_line\n"); printf("String temp inicial = '%s'\n", temp);
	if (fd >= 1000 || fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
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






















int	main(void)
{
	char	*str_line;
	int		fd = open("texto.txt", O_RDONLY);
	int		n = 0;
	int		ler = 7;

	while (n++ < ler)
	{
		printf("\nchamada = %d\n", n);

		str_line = malloc(30 * sizeof(char));
		if (!str_line)
			return (0);
		
		str_line = get_next_line(fd);

		printf("\nLinha = '%s'\n------------\n", str_line);
	}
	return (0);
}