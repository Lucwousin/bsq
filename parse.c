#include <fcntl.h>
#include <stdlib.h>
#include "map.h"

int parse_header(struct s_map map, char *buf, int len)
{
	int		i;

	if (len <= 3 || buf[len] != '\n')
		return (0);
	i = 0;
	while (i < 3)
	{
		map.symbols[i] = buf[len - 3 + i];
		if (map.symbols[i] < ' ' || map.symbols[i] > '~')
			return (0);
		++i;
	}
	map.height = 0;
	i = 0;
	while (i < len - 3)
	{
		if (buf[i] < '0' || buf[i] > '9')
			return (0);
		map.height *= 10;
		map.height += buf[i] - '0';
	}
	return (1);
}

int	parse(struct s_map *map, char *buf, int n_bytes)
{
	int	i;
	
	i = 0;
	while (i < n_bytes && buf[i] != '\n')
		++i;
	if (!parse_header(*map, buf, i))
		return (0);
	return (1);
}

int	read_file(struct s_map *map, char *file)
{
	int		fd;
	int		rv;
	char	*buf;
	
	if (file == 0)
		fd = 0;
	else
		fildes = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(100000);
	if (!buf)
	{
		close(fd);
		return (0);
	}
	 rv = parse(map, buf, read(fd, buf, 100000));
	 free(buf);
	 close(fd);
}
