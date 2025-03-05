/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilau <yilau@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:26:55 by yilau             #+#    #+#             */
/*   Updated: 2025/02/14 13:26:56 by yilau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

//A function that displays the character passed as a parameter (char c).
void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}
