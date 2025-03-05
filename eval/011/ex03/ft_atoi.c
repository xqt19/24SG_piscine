/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regillio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:48:29 by regillio          #+#    #+#             */
/*   Updated: 2025/02/24 17:04:04 by regillio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_white_space(char c)
{
	if ((c == ' ') || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	negative;

	i = 0;
	nb = 0;
	negative = 0;
	while (is_white_space(str[i]) == 1)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (negative % 2 != 0)
		return (nb * (-1));
	return (nb);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi("	 --+1234"));
}
*/
