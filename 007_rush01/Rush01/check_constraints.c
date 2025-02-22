int count_visible_buildings(int grid[4][4], int row, int col, int direction);

int check_constraints(int grid[4][4], int constraints[16])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (count_visible_buildings(grid, 0, i, 0) != constraints[i])
			return (0);
		if (count_visible_buildings(grid, 0, i, 1) != constraints[i + 4])
			return (0);
		if (count_visible_buildings(grid, i, 0, 2) != constraints[i + 8])
			return (0);
		if (count_visible_buildings(grid, i, 0, 3) != constraints[i + 12])
			return (0);
		i++;
	}
	return (1);
}