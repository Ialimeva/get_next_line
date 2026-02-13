/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:19:13 by ialrandr          #+#    #+#             */
/*   Updated: 2026/02/13 15:53:15 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buffer_read(int buffer, int fd)
{
	char	*line;
	ssize_t	bytes_readed;

	if (!buffer)
		return (NULL);
	line = (char *)malloc(buffer + 1);
	if (!line)
		return (NULL);
	bytes_readed = read(fd, line, buffer);
	line[buffer] = '\0';
	return (line);
}

int	find_slash_n(char *s, int buffer)
{
	int	i;
	int	slash_n_index;

	i = 0;
	slash_n_index = 0;
	while (i < buffer)
	{
		if (s[i] == '\n')
		{
			slash_n_index = i;
			return (slash_n_index);
		}
		i++;
	}
	return (i);
}

char	*new_line_read(char *s, int buffer)
{
	int		i;
	int		slash_n_index;
	char	*new_line;

	if (!s && !buffer)
		return (NULL);
	slash_n_index = find_slash_n(s, buffer);
	if (slash_n_index == buffer)
		return (s);
	new_line = (char *)malloc(slash_n_index + 1);
	if (!new_line)
		return (NULL);
	i = 0;
	while (i <= slash_n_index)
	{
		new_line[i] = s[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*buffer_rest(char *buffer_line, char *line_readed)
{
	char *rest;
	size_t len_buffer;
	size_t len_line_readed;

	len_buffer = ft_strlen(buffer_line);
	len_line_readed = ft_strlen(line_readed);
}
