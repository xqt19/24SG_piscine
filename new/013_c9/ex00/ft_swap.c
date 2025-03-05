/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilau <yilau@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:46:12 by yilau             #+#    #+#             */
/*   Updated: 2025/03/04 16:03:30 by yilau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return ;
}

/*
#include <stdio.h>

int	main()
{
	int	num_a;
	int	num_b;

	num_a = -123;
	num_b = 999;

	printf("Before running ft_swap - \n  num_a: %d, num_b: %d\n", num_a, num_b);
	ft_swap(&num_a, &num_b);
	printf("After running ft_swap - \n  num_a: %d, num_b: %d\n", num_a, num_b);
	return (0);
}
*/