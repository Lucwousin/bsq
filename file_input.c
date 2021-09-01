#include "bsqstructs.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#define BUF_SIZE 10000000

int	parse(struct s_map *map, char *buf, int n_bytes);

int	read_from(int fd, char *buf)
{
	int	read_b;
	int	read_just_now;
	int	to_read;

	to_read = BUF_SIZE;
	read_b = 0;
	while (1)
	{
		read_just_now = read(fd, buf, to_read - read_b);
		if (read_just_now <= 0)
			break ;
		read_b += read_just_now;
		buf += read_just_now;
	}
	return (read_b);
}

int	read_file(struct s_map *map, char *file)
{
	int		fd;
	int		rv;
	char	*buf;

	if (file == 0)
		fd = 0;
	else
		fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(BUF_SIZE);
	if (!buf)
	{
		close(fd);
		return (0);
	}
	rv = parse(map, buf, read_from(fd, buf));
	free(buf);
	close(fd);
	return (rv);
}
