/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzholama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:25:33 by rzholama          #+#    #+#             */
/*   Updated: 2025/03/05 17:40:35 by rzholama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else
	{
		if (nb > 1)
			return (nb * ft_recursive_factorial(nb - 1));
		else
			return (1);
	}
	return (0);
}
/*
#include <stdio.h>

int	main()
{
	printf("%d", ft_recursive_factorial(0));
}
*/
