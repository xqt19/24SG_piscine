int check_duplicate(int grid[4][4], int row, int col, int num)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (grid[row][i] == num) // row checker
            return (0);
        if (grid[i][col] == num) // col checker
            return (0);
        i++;
    }
    return (1);
}