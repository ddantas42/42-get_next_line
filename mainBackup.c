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


#define BUFFER_SIZE 1000000

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		n;

	if (!s)
		return (0);
	if (len > ft_strlen(((char *)s)))
		len = ft_strlen((char *)s) + 1;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	n = 0;
	while (n < len && start < ft_strlen((char *)s))
		str[n++] = s[start++];
	str[n] = '\0';
	return (str);
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
		read_size = read(fd, str, BUFFER_SIZE);		//	printf("Read_size = '%zd'\n", read_size);
		str[BUFFER_SIZE] = '\0';
		n++;
		if (read_size == 0 && str[BUFFER_SIZE - 1] == '\0')
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

int	check_if(int fd)
{
	if (!fd || fd <= 2 || fd >= 1025)
		return (0);
	if (BUFFER_SIZE <= 0)
		return (0);
	return (1);
	
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
	while (line[++n])
		temp[i++] = line[n];
	temp[i] = '\0';
	printf("String temp = '%s'\n", temp);
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
		return (NULL);
	i = -1;
	while (++i < n + 1)
		line_fix[i] = line[i];
	line_fix[++i] = '\0';
	return (line_fix);
}	

char	*get_next_line(int fd)
{
	char	*line;
	static char	*temp = "";

	printf("Começa get_next_line\n"); printf("String temp = '%s'\n", temp);
	if (check_if(fd) == 0)
		return (NULL);
	line = temp;
	line = all_string(fd, line);
	if (line[0] == 0)
		return (NULL);
	temp = string_temp(line);
	if (BUFFER_SIZE != 1)
		line = line_fix(line);
	return (line);
}






















int	main(void)
{
	char	*str_line;
	int		fd = open("texto.txt", O_RDONLY);
	int		n = 0;
	int		ler = 7;
	int		line = 0;

	while (n++ < ler)
	{
		printf("\nchamada = %d\n", ++line);

		str_line = malloc(30 * sizeof(char));
		if (!str_line)
			return (0);
		
		str_line = get_next_line(fd);

		printf("\nLinha = '%s'\n------------\n", str_line);
	}
	return (0);
}