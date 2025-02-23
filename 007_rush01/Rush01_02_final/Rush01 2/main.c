#include <unistd.h>
int count_visible_buildings(int grid[4][4], int row, int col, int direction);
int check_constraints(int grid[4][4], int constraints[16]);
int solve_grid(int grid[4][4], int row, int col, int constraints[16]);
void print_grid(int grid[4][4]);
int parse_input(char *str, int constraints[16]);

int main(int argc, char **argv)
{
	int grid[4][4] = {{0}};
	int constraints[16];
	if (argc != 2 || !parse_input(argv[1], constraints))
	{
		write(1, "Error\n", 6);
		return (1);
	}

	if (!solve_grid(grid, 0, 0, constraints))
	{
		write(1, "No solution exists\n", 18);
		return (1);
	}

	print_grid(grid);
	return (0);
}