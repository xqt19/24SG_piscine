/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:41:25 by xitan             #+#    #+#             */
/*   Updated: 2025/02/26 14:41:25 by xitan            ###   ########.fr       */
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

// #include <stdio.h>
// int	main()
// {
// 	int nb = 9;
// 	printf("%d\n",ft_sqrt(nb));
// }