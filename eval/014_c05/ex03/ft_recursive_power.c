/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzholama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:20:18 by rzholama          #+#    #+#             */
/*   Updated: 2025/03/05 17:39:07 by rzholama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	temp;

	temp = 1;
	if (power == 0 && nb == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power != 0)
	{
		power--;
		temp = nb * ft_recursive_power(nb, power);
	}
	return (temp);
}
/*
#include <stdio.h>

int	main()
{
	printf("%d", ft_recursive_power(100, 3));	

}
*/
