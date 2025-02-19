/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:22:42 by xitan             #+#    #+#             */
/*   Updated: 2025/02/19 23:22:42 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;
	char			hex[16];

	i = 0;
	while (i < 16)
	{
		if (i < 10)
			hex[i] = i + '0';
		else
			hex[i] = (i - 10) + 'a';
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= ' ' && str[i] <= '~')
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			write(1, &hex[(str[i] >> 4) & 0x0F], 1);
			write(1, &hex[str[i] & 0x0F], 1);
		}
		i++;
	}
}
