/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:17:17 by xitan             #+#    #+#             */
/*   Updated: 2025/02/18 20:58:20 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	end;
	int	num;

	index = 0;
	end = size - 1;
	while (index < end)
	{
		num = tab[index];
		tab[index] = tab[end];
		tab[end] = num;
		index++;
		end--;
	}
}
