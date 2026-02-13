/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 14:19:21 by ialrandr          #+#    #+#             */
/*   Updated: 2026/02/13 15:47:19 by ialrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*buffer_line = NULL;
	static char	*line_readed = NULL;

	if (fd < 0)
		return (NULL);
	if (buffer_line && line_readed)
	{
		free(buffer_line);
		free(line_readed);
	}
	buffer_line = buffer_read(BUFFER_SIZE, fd);
	printf("%s\n", buffer_line);
	line_readed = new_line_read(buffer_line, BUFFER_SIZE);
	printf("%s", line_readed);
	return (line_readed);
}
/*
Accumulation = Building Up:
It's like building with blocks:

First read: get block "Hello Worl"
Second read: get block "d\nThis is "
Combine them: "Hello Worl" + "d\nThis is " = "Hello World\nThis is "
Extract the first line: "Hello World\n"
Keep the rest: "This is "

*/
