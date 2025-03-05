/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzholama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:27:40 by rzholama          #+#    #+#             */
/*   Updated: 2025/03/05 17:41:15 by rzholama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;

	i = nb;
	if (nb < 0)
		return (0);
	else if (nb == 1)
		return (1);
	else
	{
		if (nb > 0)
		{
			while (i > 1)
			{
				i--;
				nb *= i;
			}
			return (nb);
		}
		else
			return (1);
	}
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	printf("Result of negative value: %d", ft_iterative_factorial(-10));
	printf("\nResult of value 0: %d", ft_iterative_factorial(0));
	printf("\nResult of value 1: %d", ft_iterative_factorial(1));
	printf("\nResult of positive value 10: %d", ft_iterative_factorial(10));

}
*/
