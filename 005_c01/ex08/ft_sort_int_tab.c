/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:31:30 by xitan             #+#    #+#             */
/*   Updated: 2025/02/18 21:24:34 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (i < size -1)
	{
		j = i +1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				num = tab[i];
				tab[i] = tab[j];
				tab[j] = num;
			}
			j++;
		}
		i++;
	}
}
