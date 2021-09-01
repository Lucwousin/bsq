#include "bsqstructs.h"
#include <unistd.h>
#include <stdlib.h>

void	try_s(struct s_map map, struct s_square *s, int size)
{
	int	x;
	int	y;

	x = s->x + size - 1;
	y = s->y;
	while (y < s->y + size)
	{
		if (x >= map.width || y >= map.height)
			return ;
		if (map.map[y][x] == map.symbols[1])
			return ;
		++y;
	}
	x = s->x;
	y = s->y + size - 1;
	while (x < s->x + size)
	{
		if (x >= map.width || y >= map.height)
			return ;
		if (map.map[y][x] == map.symbols[1])
			return ;
		++x;
	}
	s->size = size;
	try_s(map, s, size + 1);
}

struct s_square	try_square(struct s_map map, int x, int y)
{
	struct s_square	s;

	s.x = x;
	s.y = y;
	s.size = 0;
	try_s(map, &s, 1);
	return (s);
}

void	fill_square(struct s_map map, struct s_square biggest)
{
	int	xmax;
	int	ymax;
	int	x;
	int	y;

	xmax = biggest.x + biggest.size;
	ymax = biggest.y + biggest.size;
	y = biggest.y;
	while (y < ymax)
	{
		x = biggest.x;
		while (x < xmax)
		{
			map.map[y][x] = map.symbols[2];
			++x;
		}
		++y;
	}
}

void	print_map(struct s_map map)
{
	int	y;

	y = 0;
	while (y < map.height)
	{
		write(1, map.map[y], map.width);
		free(map.map[y]);
		write(1, "\n", 1);
		++y;
	}
	free(map.map);
}

void	solve(struct s_map map)
{
	struct s_square	current;
	struct s_square	biggest;
	int				x;
	int				y;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			current = try_square(map, x, y);
			if (current.size > biggest.size)
				biggest = current;
			++x;
		}
		++y;
	}
	fill_square(map, biggest);
	print_map(map);
}
