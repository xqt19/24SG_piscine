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