#include <unistd.h>

void print_grid(int grid[4][4])
{
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            write(1, &"0123456789"[grid[i][j]], 1);
            if (j < 3)
                write(1, " ", 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

int check_duplicate(int grid[4][4], int row, int col, int num)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (grid[row][i] == num)
            return (0);
        if (grid[i][col] == num)
            return (0);
        i++;
    }
    return (1);
}

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

int solve_grid(int grid[4][4], int row, int col, int constraints[16])
{
    int num;

    if (row == 4) // basecase to check if 4th row is reached
        return (check_constraints(grid, constraints)); // 
    
    if (col == 4)
        return (solve_grid(grid, row + 1, 0, constraints));

    num = 1;
    while (num <= 4)
    {
        if (check_duplicate(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solve_grid(grid, row, col + 1, constraints))
                return (1);
        }
        num++;
    }
    grid[row][col] = 0;
    return (0);
}

int parse_input(char *str, int constraints[16])
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i])
    {
        if (i % 2 == 0)
        {
            if (str[i] < '1' || str[i] > '4')
                return (0);
            constraints[j++] = str[i] - '0';
        }
        else if (str[i] != ' ')
            return (0);
        i++;
    }
    if (j != 16)
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
	int grid[4][4] = {{0}};
	int constraints[16] = {4, 3, 2, 1, 1, 2, 2, 2, 4, 3, 2, 1, 1, 2, 2, 2};
	(void) argc;
	(void) argv;
	// if (argc != 2 || !parse_input(argv[1], constraints))
	// {
	// 	write(1, "Error\n", 6);
	// 	return (1);
	// }

	if (!solve_grid(grid, 0, 0, constraints)) 
	{
		write(1, "No solution exists\n", 18);
		return (1);
	}

	print_grid(grid);
	return (0);
}