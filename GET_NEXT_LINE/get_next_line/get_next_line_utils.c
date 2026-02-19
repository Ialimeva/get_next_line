/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:16:01 by ialrandr          #+#    #+#             */
/*   Updated: 2026/02/19 13:12:59 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *buffer_line)
{
	int	i;

	if (!buffer_line)
		return (0);
	i = 0;
	while (buffer_line[i])
	{
		if (buffer_line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	check_newline(char *buffer_line)
{
	int	i;

	if (!buffer_line)
		return (0);
	i = 0;
	while (buffer_line[i])
	{
		if (buffer_line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_until_newline(char *buffer_line, int fd)
{
	char	*new_buffer;

	while (check_newline(buffer_line) == 0)
	{
		new_buffer = buffer_read(BUFFER_SIZE, fd);
		if (!new_buffer)
			break ;
		buffer_line = string_combo(buffer_line, new_buffer);
	}
	return (buffer_line);
}

size_t	ft_slen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*string_combo(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*res;
	size_t	str1_len;
	size_t	str2_len;

	if (!str1 || !str2)
		return (NULL);
	i = 0;
	str1_len = ft_slen(str1);
	str2_len = ft_slen(str2);
	res = (char *)malloc(str1_len + str2_len + 1);
	if (!res)
		return (NULL);
	while (str1[i])
	{
		res[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
		res[i++] = str2[j++];
	res[i] = '\0';
	return (free(str1), free(str2), res);
}
