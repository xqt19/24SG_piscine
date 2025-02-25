/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:27:25 by xitan             #+#    #+#             */
/*   Updated: 2025/02/25 18:26:47 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (1);
	return (i);
}

void	ft_print(int nbr, char *base, int size)
{
	if (nbr >= size)
		ft_print (nbr / size, base, size);
	write(1, &base[nbr % size], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	size;

	if (nbr < -2147483647 || nbr > 2147483647)
		return ;
	size = check_base(base);
	if (size == 1)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	ft_print(nbr, base, size);
}

// int	main()
// {
// // 	// int num = -103384;
// // 	// char *base = "AbcdeFghij";
// 	int num = -7;
// 	char *base = "01";
// 	ft_putnbr_base(num, base);
// }