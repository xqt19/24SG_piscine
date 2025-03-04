#include <stdio.h>
#include "ft_point.h"

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int	main(void)
{
	t_point	point;

	point.x = 0;
	point.y = 0;

	printf("Before: x = %d, y = %d\n", point.x, point.y);
	set_point(&point);
	printf("After: x = %d, y = %d\n", point.x, point.y);
	return (0);
}