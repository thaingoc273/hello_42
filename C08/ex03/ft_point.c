#include "ft_point.h"

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

#include <stdio.h>

int	main(void)
{
	t_point	point;
	set_point(&point);
	printf("Value of x: %d\n", point.x);
	printf("Value of y: %d\n", point.y);
	return (0);
}
