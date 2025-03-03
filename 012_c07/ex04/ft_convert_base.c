/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:21:43 by xitan             #+#    #+#             */
/*   Updated: 2025/03/03 20:23:41 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_itoa(char *res, int num, char *base_to, int base_to_size);
int		is_valid(char c, char *base_from);

int	base_convert(char *substr, char *base_from, int base_size)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = 0;
	while (substr[i] != '\0' && is_valid(substr[i], base_from))
	{
		j = 0;
		while (base_from[j] != '\0')
		{
			if (substr[i] == base_from[j])
			{
				num *= base_size;
				num += j;
			}
			j++;
		}
		i++;
	}
	return (num);
}

int	ft_atoi(char *str, char *base_from, int base_size)
{
	int		i;
	int		negative;
	char	*substr;

	i = 0;
	while (((str[i] >= '\t') && (str[i] <= '\r')) || str[i] == ' ')
		i++;
	negative = 1;
	while ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	substr = &str[i];
	if (negative == -1)
		return (-1 * base_convert(substr, base_from, base_size));
	return (base_convert(substr, base_from, base_size));
}

int	check_base(char *base)
{
	int	i;
	int	j;

	if ((base == 0) || (base[0] == '\0') || (base[1] == '\0'))
		return (1);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == '\t'
			|| base[i] == '\n' || base[i] == '\v' || base[i] == '\f'
			|| base[i] == '\r' || base[i] == ' ')
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_from_size;
	int		base_to_size;
	int		num;
	char	*res;

	if (check_base(base_from) || check_base(base_to))
		return (0);
	base_from_size = 0;
	while (base_from[base_from_size] != '\0')
		base_from_size++;
	base_to_size = 0;
	while (base_to[base_to_size] != '\0')
		base_to_size++;
	num = 0;
	num = ft_atoi(nbr, base_from, base_from_size);
	res = (char *)malloc((sizeof(char)) * 33);
	ft_itoa(res, num, base_to, base_to_size);
	return (res);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*base_from;
// 	char	*base_to;
// 	char	*out_str;

// 	str = "-15";
// 	base_from = "0123456789";
// 	base_to = "01";
// 	out_str = ft_convert_base(str, base_from, base_to);
// 	printf("Test 1: %s\n", out_str);
// }