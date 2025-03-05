/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzholama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:07:47 by rzholama          #+#    #+#             */
/*   Updated: 2025/03/05 17:34:51 by rzholama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;
	int	temp;

	temp = 0;
	i = 1;
	while (i <= nb)
	{
		if (nb % i == 0)
			temp++;
		i++;
	}
	if (temp == 2)
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	int prime = 10;
	
	printf("[1] - for prime values, and [0] - for non prime.\n");
	printf("The value of {%d} is: %d ", prime, ft_is_prime(prime));
}
*/
