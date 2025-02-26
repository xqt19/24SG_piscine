/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:59:32 by xitan             #+#    #+#             */
/*   Updated: 2025/02/26 14:59:32 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_sqrt(int nb)
{
	int	num;

	if (nb < 0)
		return (0);
	num = 0;
	while (num * num <= nb)
	{
		if (num * num == nb)
			return (num);
		num++;
	}
	return (0);
}

int	ft_is_prime(int nb)
{
	int	i;

	if (nb == 2)
		return (1);
	if (nb <= 1 || nb % 2 == 0)
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

// #include <stdio.h>
// int	main()
// {
// 	int nb = 30;
//     for (int i=-5;i<=nb;i++){
//         printf("%d - %d\n",i,ft_is_prime(i));
//     }
// }