/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:03:52 by xitan             #+#    #+#             */
/*   Updated: 2025/02/27 22:31:46 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*arr;

	if (min >= max)
		return (NULL);
	arr = (int *) malloc((max - min) * (sizeof(int)));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (min + i < max)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

// #include <stdio.h>
// int	main()
// {
// 	int num1 = 10;
// 	int num2 = 21;
// 	int *arr = ft_range(num1,num2);
// 	if (arr == NULL)
// 		printf("%s","It is null!");
// 	else
// 	{
// 		for(int i=0; i<(num2-num1);i++)
// 			printf("%d-",arr[i]);
// 	}
// }