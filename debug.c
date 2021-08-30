#include "map.h"
#include <stdio.h>

void	print(struct s_map map)
{
	printf("%dx%d%c%c%c", map.width, map.height, map.symbols[0], map.symbols[1], map.symbols[2]);
	for (int y = 0; y < map.height; y++)
	{
		for (int x = 0; x < map.width; x++)
			printf("%c", map.map[y][x]);
		printf("\n");
	}
}
