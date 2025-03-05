/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzholama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:05:56 by rzholama          #+#    #+#             */
/*   Updated: 2025/03/05 17:33:36 by rzholama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int nb)
{
	int	i;
	int	temp;

	temp = 0;
	i = 1;
	while (i <= nb)
	{
		if (nb % i == 0)
			temp++;
		i++;
	}
	if (temp == 2)
		return (1);
	return (0);
}

int	ft_find_next_prime(int nb)
{
	while (!(is_prime(nb)))
	{
		nb++;
	}
	return (nb);
}
/*
#include <stdio.h>

int main()
{
	int num = -1;
	printf("%d", ft_find_next_prime(num));
}
*/
