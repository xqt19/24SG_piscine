/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:29:28 by xitan             #+#    #+#             */
/*   Updated: 2025/02/15 21:00:15 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int c, int r)
{
	int	i;
	int	j;

	i = 1;
	while (i <= r)
	{
		j = 1;
		while (j <= c)
		{
			if (i == 1 && j == 1)
				ft_putchar('A');
			else if ((i == 1 && j == c) || (i == r && j == 1))
				ft_putchar('C');
			else if (i == r && j == c)
				ft_putchar('A');
			else if (i == 1 || i == r || j == 1 || j == c)
				ft_putchar('B');
			else
				ft_putchar(' ');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}
