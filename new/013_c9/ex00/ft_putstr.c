/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilau <yilau@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:35:28 by yilau             #+#    #+#             */
/*   Updated: 2025/03/04 16:04:16 by yilau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	return ;
}

/*
int	main(void)
{
	char	string1[] = "abufu12345";
	char	string2[] = "!@ #$^&*(c)-+";
	char	string3[50] = "123";

	ft_putstr(string1);
	write(1, "\n", 1);
	ft_putstr(string2);
	write(1, "\n", 1);
	ft_putstr(string3);
	write(1, "\n", 1);
	return (0);
}
*/