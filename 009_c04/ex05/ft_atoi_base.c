/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:14:54 by xitan             #+#    #+#             */
/*   Updated: 2025/02/25 18:02:07 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <unistd.h>
// #include <stdio.h>
// #include <string.h>

// int	check_base(char *base)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (base[i])
// 	{
// 		if (base[i] == '+' || base[i] == '-')
// 			return (1);
// 		j = i + 1;
// 		while (base[j])
// 		{
// 			if (base[i] == base[j])
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (i < 2)
// 		return (1);
// 	return (i);
// }

// int	ft_print(int nbr, int size)
// {
// 	int num;

// 	num = 0;

// 	while (nbr > 0)
// 	{
// 		// printf("%d\n", nbr);
// 		num *= 10;
// 		num += nbr % size;
// 		nbr /= size;
// 	}
// 	return (num);
// }

// int	ft_atoi(char *str)
// {
// 	int	negative;
// 	int	num;

// 	num = 0;
// 	negative = 1;
// 	while (*str == ' ')
// 		str++;
// 	while (*str == '+' || *str == '-')
// 	{
// 		if (*str == '-')
// 			negative *= -1;
// 		str++;
// 	}
// 	while (*str >= '0' && *str <= '9')
// 	{
// 		num *= 10;
// 		num += (*str - 48);
// 		str++;
// 	}
// 	return (negative * num);
// }

// int	ft_atoi_base(char *str, char *base)
// {
// 	int	size;
// 	int nbr;

// 	size = check_base(base);
// 	if (size == 1)
// 		return (0);
// 	nbr = ft_atoi(str);
// 	if (nbr < 0)
// 	{
// 		write(1, "-", 1);
// 		nbr *= -1;
// 	}
// 	return(ft_print(ft_print(nbr, size),size));
// }

// int	main()
// {
// // 	// int num = -103384;
// // 	// char *base = "AbcdeFghij";
// 	char *str = "-baddie"; // -103384
// 	char *base = "abcdefghij";
// 	printf("%d\n", ft_atoi_base(str, base));
// }