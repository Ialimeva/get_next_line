/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 10:16:06 by ialrandr          #+#    #+#             */
/*   Updated: 2026/02/19 13:12:46 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buffer_read(int buffer, int fd)
{
	char	*res;
	ssize_t	bytes_readed;

	if (!buffer || fd < 0)
		return (NULL);
	res = (char *)malloc(buffer + 1);
	if (!res)
		return (NULL);
	bytes_readed = read(fd, res, buffer);
	if (bytes_readed <= 0)
		return (free(res), NULL);
	res[bytes_readed] = '\0';
	return (res);
}

char	*extract_line(char *buffer_line)
{
	int		i;
	char	*res;
	int		newline_index;

	if (!buffer_line)
		return (NULL);
	i = 0;
	newline_index = find_newline(buffer_line);
	if (newline_index == -1)
		newline_index = ft_slen(buffer_line) - 1;
	res = (char *)malloc(newline_index + 2);
	if (!res)
		return (NULL);
	while (i <= newline_index)
	{
		res[i] = buffer_line[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*leftover(char *buffer_line, char *extracted_line)
{
	size_t	i;
	size_t	j;
	size_t	buffer_len;
	size_t	extracted_len;
	char	*res;

	if (!buffer_line || !extracted_line)
		return (free(buffer_line), NULL);
	i = 0;
	buffer_len = ft_slen(buffer_line);
	extracted_len = ft_slen(extracted_line);
	res = (char *)malloc(buffer_len - extracted_len + 1);
	if (!res)
		return (NULL);
	while (buffer_line[i] == extracted_line[i] && buffer_line[i]
		&& extracted_line[i])
		i++;
	j = 0;
	while (buffer_line[i])
		res[j++] = buffer_line[i++];
	res[j] = '\0';
	if (j == 0)
		return (free(buffer_line), free(res), NULL);
	return (free(buffer_line), res);
}

char	*empty_leftover(char **buffer_line, char **leftover_line, int fd)
{
	char	*extracted_line;

	if (!*buffer_line)
		return (NULL);
	*buffer_line = read_until_newline(*buffer_line, fd);
	extracted_line = extract_line(*buffer_line);
	*leftover_line = leftover(*buffer_line, extracted_line);
	return (extracted_line);
}

char	*get_next_line(int fd)
{
	char		*buffer_line;
	char		*temp;
	char		*extracted_line;
	static char	*leftover_line;

	if (fd < 0)
		return (NULL);
	buffer_line = buffer_read(BUFFER_SIZE, fd);
	if (!leftover_line)
		return (empty_leftover(&buffer_line, &leftover_line, fd));
	if (buffer_line)
	{
		buffer_line = read_until_newline(buffer_line, fd);
		temp = string_combo(leftover_line, buffer_line);
		extracted_line = extract_line(temp);
		leftover_line = leftover(temp, extracted_line);
		return (extracted_line);
	}
	free(buffer_line);
	extracted_line = extract_line(leftover_line);
	if (!extracted_line || ft_slen(extracted_line) == ft_slen(leftover_line))
		return (free(leftover_line), leftover_line = NULL, extracted_line);
	leftover_line = leftover(leftover_line, extracted_line);
	return (extracted_line);
}
