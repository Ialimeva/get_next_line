#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("42.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
}
