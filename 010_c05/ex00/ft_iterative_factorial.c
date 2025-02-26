/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:46:40 by xitan             #+#    #+#             */
/*   Updated: 2025/02/26 10:46:40 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_factorial(int nb)
{
	unsigned int	num;

	num = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		num *= nb;
		nb -= 1;
	}
	return (num);
}

// #include <stdio.h>
// int	main()
// {
// 	int	nb = 5; //120
// 	printf("%d", ft_iterative_factorial(nb));
// }