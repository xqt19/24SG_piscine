/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzholama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:24:04 by rzholama          #+#    #+#             */
/*   Updated: 2025/03/05 17:39:55 by rzholama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	temp;

	temp = 1;
	if (power == 0 && nb == 0)
		return (1);
	else if (nb == 0 || power < 0)
		return (0);
	else
	{
		while (power != 0)
		{
			temp *= nb;
			--power;
		}
		return (temp);
	}
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	printf("%d", ft_iterative_power(-3, 3));
}
*/
