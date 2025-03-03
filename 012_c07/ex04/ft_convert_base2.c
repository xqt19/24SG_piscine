/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:21:46 by xitan             #+#    #+#             */
/*   Updated: 2025/03/03 20:22:05 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_swap(char *a, char *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_char_tab(char *res, int res_len, int negative)
{
	int	i;

	i = 0;
	if (negative == -1)
		res[res_len++] = '-';
	while (i < (res_len) / 2)
	{
		ft_swap(&res[i], &res[(res_len - i) - 1]);
		i++;
	}
}

void	base_parse(char *res, char *base_to, int res_len)
{
	int	i;

	i = 0;
	while (i < res_len)
	{
		res[i] = base_to[((int)(res[i] - '0'))];
		i++;
	}
}

void	ft_itoa(char *res, int num, char *base_to, int base_to_size)
{
	int	negative;
	int	i;
	int	res_len;

	negative = 1;
	if (num < 0)
	{
		negative = -1;
		num = -num;
	}
	i = 0;
	while (num != 0)
	{
		res[i] = (num % base_to_size) + '0';
		num /= base_to_size;
		i++;
	}
	if (i == 0)
		res[i++] = '0';
	res_len = i;
	base_parse(res, base_to, res_len);
	ft_rev_char_tab(res, res_len, negative);
}

int	is_valid(char c, char *base_from)
{
	int	i;

	i = 0;
	while (base_from[i] != '\0')
	{
		if (base_from[i] == c)
			return (1);
		i++;
	}
	return (0);
}
