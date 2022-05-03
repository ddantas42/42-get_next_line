/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddantas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:10:23 by ddantas-          #+#    #+#             */
/*   Updated: 2022/04/04 15:19:30 by ddantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

// Main Functions
char		*all_string(int fd, char *line);
char		*string_temp(char *line);
char		*line_fix(char *line);
char		*get_next_line(int fd);

// helper Functions
size_t		ft_strlen(char *s);
int			check_lines(char *string);
char		*ft_strjoin(char *str, char *line);
char		*clean_str(char str[BUFFER_SIZE + 1]);
#endif