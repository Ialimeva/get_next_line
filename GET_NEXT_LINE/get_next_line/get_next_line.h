/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:16:11 by ialrandr          #+#    #+#             */
/*   Updated: 2026/02/19 12:39:40 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*buffer_read(int buffer, int fd);
int		find_newline(char *buffer_line);
char	*extract_line(char *buffer_line);
size_t	ft_slen(char *s);
char	*leftover(char *buffer_line, char *extracted_line);
char	*string_combo(char *str1, char *str2);
char	*read_until_newline(char *buffer_line, int fd);
char	*empty_leftover(char **buffer_line, char **leftover_line, int fd);

#endif
