#ifndef BSQSTRUCTS_H
# define BSQSTRUCTS_H

struct	s_map
{
	int		height;
	int		width;
	char	symbols[3];
	char	**map;
};

struct	s_square
{
	int	x;
	int	y;
	int	size;
};

#endif
