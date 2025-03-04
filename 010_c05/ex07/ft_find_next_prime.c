/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:17:37 by xitan             #+#    #+#             */
/*   Updated: 2025/02/26 15:17:37 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt(int nb)
{
	long	num;

	if (nb < 0)
		return (0);
	num = 0;
	while (num * num <= nb)
	{
		if (num * num == nb)
			return (num);
		num++;
	}
	return (num);
}

int	is_prime(int nb)
{
	int	i;

	if (nb % 2 == 0)
		return (0);
	i = 3;
	while (i <= ft_sqrt(nb))
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	if (is_prime(nb))
		return (nb);
	return (ft_find_next_prime(nb + 1));
}

// #include <stdio.h>
// int	main()
// {
// 	for (int i=-5; i<21;i++){
// 		printf("%d - %d\n",i,ft_find_next_prime(i));
// 	}
// }