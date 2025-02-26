/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 12:29:01 by xitan             #+#    #+#             */
/*   Updated: 2025/02/26 12:29:01 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		while (power > 1)
		{
			res *= nb;
			power--;
		}
	}
	return (res);
}

// #include <stdio.h>
// int	main()
// {
// 	int nb = 2;
// 	int power = 4;
// 	printf("%d\n",ft_iterative_power(nb,power));
// }