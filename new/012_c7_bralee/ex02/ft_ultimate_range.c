/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bralee <bralee@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:51:28 by bralee            #+#    #+#             */
/*   Updated: 2025/02/25 15:51:29 by bralee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

// int	main(void)
// {
// 	int	*int_arr;
// 	int	i;
// 	int	start;
// 	int	endbefore;
// 	int	size;

// 	start = 15;
// 	endbefore = 17;
// 	size = ft_ultimate_range(&int_arr, start, endbefore);
// 	printf("%d\n%p\n", size, int_arr);
// 	i = 0;
// 	while (i < (endbefore - start))
// 	{
// 		printf("%d ", int_arr[i]);
// 		i++;
// 	}
// 	free(int_arr);
// 	printf("\n");
// 	i = 0;
// 	while (i < (endbefore - start))
// 	{
// 		printf("%d ", int_arr[i]);
// 		i++;
// 	}
// 	return (0);
// }

int	ft_ultimate_range(int **range, int min, int max)
{
	int	idx;
	int	size;
	int	*arr;

	size = max - min;
	idx = 0;
	if (size <= 0)
	{
		arr = 0;
		*range = arr;
		return (0);
	}
	else
	{
		arr = (int *)malloc(sizeof(int) * size);
		if (arr == NULL)
			return (-1);
		while (idx < size)
		{
			arr[idx] = min + idx;
			idx++;
		}
		*range = arr;
		return (size);
	}
}
