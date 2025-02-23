int get_height(int grid[4][4], int pos, int row, int col, int is_vertical)
{
	if (is_vertical)
		return grid[pos][col];
	return grid[row][pos];
}

int count_visible_buildings_helper(int grid[4][4], int start, int end, int step, 
								 int row, int col, int is_vertical)
{
	int i = start + step;
	int visible = 1;
	int max_height = get_height(grid, start, row, col, is_vertical);

	while (i != end + step)
	{
		if (get_height(grid, i, row, col, is_vertical) > max_height)
		{
			visible++;
			max_height = get_height(grid, i, row, col, is_vertical);
		}
		i += step;
	}
	return visible;
}

int count_visible_buildings(int grid[4][4], int row, int col, int direction)
{
	if (direction == 0)  // top to bottom
		return count_visible_buildings_helper(grid, 0, 3, 1, row, col, 1);
	else if (direction == 1)  // bottom to top
		return count_visible_buildings_helper(grid, 3, 0, -1, row, col, 1);
	else if (direction == 2)  // left to right
		return count_visible_buildings_helper(grid, 0, 3, 1, row, col, 0);
	else  // right to left
		return count_visible_buildings_helper(grid, 3, 0, -1, row, col, 0);
}