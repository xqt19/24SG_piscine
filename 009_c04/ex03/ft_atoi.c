/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:06:32 by xitan             #+#    #+#             */
/*   Updated: 2025/02/25 13:42:27 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	negative;
	int	num;

	num = 0;
	negative = 1;
	while (*str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += (*str - 48);
		str++;
	}
	return (negative * num);
}

// int main (int argc, char *argv[]){
// 	if (argc != 2) 
// 	{
//         printf("Invalid Input");
//         return 0;
//     }
// // 	// char str[] = "     ---+--+1234ab567"; // -1234
// // 	// char str1[] = "     ---+- -+1234ab567"; //0 because of invalid space
// // 	// char str2[] = "     -a--+--+1234ab567"; // 0 becasue of invalid a
// // 	// char str3[] = "+-123 4567"; // -123
// // 	// char str4[] = ""; // 0
// 	printf("%d\n", ft_atoi(argv[1]));
// }
