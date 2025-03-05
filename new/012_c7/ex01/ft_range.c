/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bralee <bralee@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:51:21 by bralee            #+#    #+#             */
/*   Updated: 2025/02/25 15:51:22 by bralee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <stdio.h>

int	*ft_range(int min, int max);

// int	main(void)
// {
// 	int	*array;
// 	int	i;
// 	int	start;
// 	int	endbefore;

// 	start = 15;
// 	endbefore = 25;
// 	array = ft_range(start, endbefore);
// 	printf("%p\n", array);
// 	i = 0;
// 	while (i < endbefore - start)
// 	{
// 		printf("%d ", array[i]);
// 		i++;
// 	}
// 	free(array);
// 	printf("\n");
// 	i = 0;
// 	while (i < endbefore - start)
// 	{
// 		printf("%d ", array[i]);
// 		i++;
// 	}
// 	return (0);
// }

int	*ft_range(int min, int max)
{
	unsigned int	idx;
	unsigned int	size;
	int				*int_range;

	size = max - min;
	idx = 0;
	if ((max - min) <= 0)
	{
		int_range = 0;
	}
	else
	{
		int_range = (int *)malloc(sizeof(int) * size);
		if (int_range == NULL)
			return (NULL);
		while (idx < size)
		{
			int_range[idx] = min + idx;
			idx++;
		}
	}
	return (int_range);
}
