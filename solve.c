#include "bsqstructs.h"

void try_s(struct s_map map, struct s_square *s, int size)
{
	int x;
	int y;
	int	xmax;
	int ymax;

	ymax = s->y + size;
	xmax = s->x + size;
	y = s->y;
	while (y < ymax)
	{
		x = s->x;
		while (x < xmax)
		{
			if (x >= map.width || y >= map.height)
				return ;
			if (map.map[y][x] == map.symbols[1])
				return ;
			++x;
		}
		++y;
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

void solve(struct s_map map)
{
	struct s_square	current;
	struct s_square	biggest;
	int 			x;
	int 			y;

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
	printf("%d, %d size %d\n", biggest.x, biggest.y, biggest.size);
}
