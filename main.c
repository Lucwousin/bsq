#include <unistd.h>
#include "map.h"

int	read_file(struct s_map *map, char *file);

void	map_error(void)
{
	write(1, "map error", 9);
}

void	solve(struct s_map map)
{
}

int	main(int argc, char **argv)
{
	struct s_map	map;
	int				i;

	if (argc == 1)
	{
		if (!read_file(&map, 0))
			map_error();
		else
			solve(map);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			if (!read_file(&map, argv[i]))
				map_error();
			else
				solve(map);
			write(1, "\n", 1);
		}
	}
}
