#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "map.h"

void	print(struct s_map map);

int	parse_header(struct s_map *map, char *buf, int len)
{
	int		i;

	if (len <= 3 || buf[len] != '\n')
		return (0);
	i = 0;
	while (i < 3)
	{
		map->symbols[i] = buf[len - 3 + i];
		if (map->symbols[i] < ' ' || map->symbols[i] > '~')
			return (0);
		++i;
	}
	map->height = 0;
	i = 0;
	while (i < len - 3)
	{
		if (buf[i] < '0' || buf[i] > '9')
			return (0);
		map->height *= 10;
		map->height += buf[i] - '0';
		++i;
	}
	return (1);
}

int	allocate_map(struct s_map *map)
{
	int		i;
	char	**mapmap;

	i = 0;
	mapmap = malloc(map->height * sizeof(char *));
	if (!mapmap)
		return (0);
	while (i < map->height)
	{
		mapmap[i] = malloc(map->width * sizeof(char));
		if (!mapmap[i])
			return (0);
		++i;
	}
	map->map = mapmap;
	return (1);
}

int	fill_map(struct s_map *map, char *buf)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (*buf == '\n'
				|| (*buf != map->symbols[0] && *buf != map->symbols[1]))
				return (0);
			map->map[y][x] = *buf;
			++buf;
			++x;
		}
		++buf;
		++y;
	}
	return (1);
}

int	parse(struct s_map *map, char *buf, int n_bytes)
{
	int	i;
	int	start_map;

	i = 0;
	while (i < n_bytes && buf[i] != '\n')
		++i;
	if (!parse_header(map, buf, i++))
		return (0);
	map->width = 0;
	start_map = i;
	while (i < n_bytes && buf[i] != '\n')
	{
		++i;
		++map->width;
	}
	if (((n_bytes - i + 1) / (map->width + 1)) != map->height - 1)
		return (0);
	if (!allocate_map(map))
		return (0);
	if (!fill_map(map, buf + start_map))
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
		fd = open(file, O_RDONLY);
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
	 return (rv);
}
