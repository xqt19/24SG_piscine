#include <stdio.h>
#include <unistd.h>
int count_visible_buildings(int grid[4][4], int row, int col, int direction);

int check_constraints(int grid[4][4], int constraints[16])
{
	int i;

	i = 0;
	while (i < 4)
	{
		printf("Broke at: ");
		if (count_visible_buildings(grid, 0, i, 0) != constraints[i])
			{
				printf("%s", "TB ");
				printf("%s", "Row: ");
				printf("%d ", 0);
				printf("%s ", "Col:");
				printf("%d \n", i);
				return (0);
			}
		if (count_visible_buildings(grid, 0, i, 1) != constraints[i + 4])
			{
				printf("%s ", "BT");
				printf("%s ", "Row:");
				printf("%d ", 0);
				printf("%s ", "Col:");
				printf("%d \n", i);
				return (0);
			}
		if (count_visible_buildings(grid, i, 0, 2) != constraints[i + 8])
			{
				printf("%s ", "LR");
				printf("%s ", "Row:");
				printf("%d ", i);
				printf("%s ", "Col:");
				printf("%d \n", 0);
				return (0);
			}
		if (count_visible_buildings(grid, i, 0, 3) != constraints[i + 12])
			{
				printf("%s ", "LR");
				printf("%s ", "Row:");
				printf("%d ", i);
				printf("%s ", "Col:");
				printf("%d \n", 0);
				return (0);
			}
		i++;
	}
	return (1);
}