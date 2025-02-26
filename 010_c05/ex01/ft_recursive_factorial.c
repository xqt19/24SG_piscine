/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:49:34 by xitan             #+#    #+#             */
/*   Updated: 2025/02/26 11:49:34 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 1 || nb == 0)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}

// #include <stdio.h>
// int	main()
// {
// 	int	nb = 5; //120
// 	printf("%d", ft_recursive_factorial(nb));
// }

// // other main for taking arguments from cmd please ignore
// #include <stdio.h>
// int	main(int argc, char *argv[])
// {
// 	if (argc == 2)
// 	{
// 		int i = 0;
// 		int num = 0;
// 		while (argv[1][i])
// 			i++;
// 		i = 0;
// 		while (argv[1][i])
// 		{
// 			num *= 10;
// 			num += argv[1][i] - 48;
// 			i++;
// 		}
// 		printf("%d\n",ft_recursive_factorial(num));
// 	}
// }