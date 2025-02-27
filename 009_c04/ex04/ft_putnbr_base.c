/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:27:25 by xitan             #+#    #+#             */
/*   Updated: 2025/02/27 17:01:35 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned int	check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

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

void	ft_print(unsigned int nbr, char *base, unsigned int size)
{
	if (nbr >= size)
		ft_print (nbr / size, base, size);
	write(1, &base[nbr % size], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	size;
	unsigned int	num;

	size = check_base(base);
	if (size == 1)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr == -2147483648)
			num = (unsigned int)(2147483648);
		else
			num = (unsigned int)(-nbr);
	}
	else
		num = (unsigned int)(nbr);
	ft_print(num, base, size);
}

// int	main()
// {
// 	// int num = -2147483647;
// 	// char *base = "0123456789";
// 	int num = -7;
// 	char *base = "01";
// 	ft_putnbr_base(num, base);
// }