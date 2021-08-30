#include "map.h"
#include <stdio.h>

void	print(struct s_map map)
{
	printf("%dx%d%c%c%c", map.width, map.height, map.symbols[0], map.symbols[1], map.symbols[2]);
}
