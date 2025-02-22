int count_visible_buildings(int grid[4][4], int row, int col, int direction)
{
	int i;
	int visible;
	int max_height;

	visible = 1;
	if (direction == 0)  // top to bottom
	{
		max_height = grid[0][col];
		i = 1;
		while (i < 4)
		{
			if (grid[i][col] > max_height)
			{
				visible++;
				max_height = grid[i][col];
			}
			i++;
		}
	}
	else if (direction == 1)  // bottom to top
	{
		max_height = grid[3][col];
		i = 2;
		while (i >= 0)
		{
			if (grid[i][col] > max_height)
			{
				visible++;
				max_height = grid[i][col];
			}
			i--;
		}
	}
	else if (direction == 2)  // left to right
	{
		max_height = grid[row][0];
		i = 1;
		while (i < 4)
		{
			if (grid[row][i] > max_height)
			{
				visible++;
				max_height = grid[row][i];
			}
			i++;
		}
	}
	else  // right to left
	{
		max_height = grid[row][3];
		i = 2;
		while (i >= 0)
		{
			if (grid[row][i] > max_height)
			{
				visible++;
				max_height = grid[row][i];
			}
			i--;
		}
	}
	return (visible);
}