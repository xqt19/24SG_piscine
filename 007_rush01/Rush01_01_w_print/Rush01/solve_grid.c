#include <unistd.h>
#include <stdio.h>

int check_constraints(int grid[4][4], int constraints[16]);
int check_duplicate(int grid[4][4], int row, int col, int num);
void print_grid(int grid[4][4]);

int solve_grid(int grid[4][4], int row, int col, int constraints[16])
{
	int num;

	if (row == 4)
			return (check_constraints(grid, constraints));
	if (col == 4)
		return (solve_grid(grid, row + 1, 0, constraints));

	num = 1;
	while (num <= 4)
	{
		printf("Row: %d, Col: %d, Num: %d\n", row+1, col+1, num);
		if (check_duplicate(grid, row, col, num))
		{
			grid[row][col] = num;
			print_grid(grid);
			write(1, "\n", 1);
			if (solve_grid(grid, row, col + 1, constraints))
				return (1);
		}
		num++;
	}
	grid[row][col] = 0;
	return (0);
}