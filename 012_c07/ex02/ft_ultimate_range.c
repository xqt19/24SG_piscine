/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:57:53 by xitan             #+#    #+#             */
/*   Updated: 2025/03/02 16:14:24 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	size;

	size = max - min;
	if (size <= 0)
	{
		*range = 0;
		return (0);
	}
	*range = (int *) malloc((size) * (sizeof(int)));
	if (range == NULL)
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (size);
}

// #include <stdio.h>
// int	main()
// {
// 	int num1 = -9;
// 	int num2 = 10;
// 	int *range;
// 	int size = ft_ultimate_range(&range, num1,num2);
// 	printf("size is %d\n",size);
// 	if (range == NULL)
// 		printf("%s","It is null!");
// 	else
// 	{
// 		for (int i = 0; i < size; i++) {
// 			printf("%d ", range[i]);
// 		}
// 		printf("\n");
// 	}
// }