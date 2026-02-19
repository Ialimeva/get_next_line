#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*file;
	char	*line;

	/* int		c */;
	(void)argc;
	file = argv[1];
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
}
