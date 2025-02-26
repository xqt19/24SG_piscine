/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:34:08 by xitan             #+#    #+#             */
/*   Updated: 2025/02/26 16:34:08 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	generate_grid(int grid[])
{
	int i;

	i = 0;
	while (i<10)
	{
		grid[i] = 9;
		i++;
	}
}

int	check_grid(int grid[], int num)
{
	int	i;

	i = 0;
	while (i < 10)
    {
        if (grid[i] == num) // row checker
            return (0);
        i++;
    }
    return (1);
}

void	print_grid(int grid[])
{
	printf("[%d,%d,%d,%d,%d,%d,%d,%d,%d,%d]\n",grid[0], grid[1], grid[2], grid[3], grid[4], 
		grid[5], grid[6], grid[7], grid[8], grid[9]);
}

void	place_grid(int grid[], int col)
{
	int num;

	if (col == 10)
		return ;

	num = 0;
	while (num <= 10)
	{
		if (check_grid(grid, num))
			grid[col] = num;
		place_grid(grid, col+1);
		num++;
	}
	print_grid(grid);
	grid[col] = 0;
}

int	ft_ten_queens_puzzle(void)
{
	int	grid[10];
	generate_grid(grid);
	place_grid(grid, 0);
	print_grid(grid);
	return (0);
}

#include <stdio.h>
int	main()
{
	ft_ten_queens_puzzle();
}