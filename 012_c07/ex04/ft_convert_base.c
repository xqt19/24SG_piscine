/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:21:43 by xitan             #+#    #+#             */
/*   Updated: 2025/03/02 17:38:23 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

//TODO base convert

int	ft_atoi(char *str, char *base_from, int base_size)
{
	int		i;
	int		negative;
	char	*substr;
	char	int_str[999];

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
		return (-1 * base_convert(substr, int_str, base_from, base_size));
	return (base_convert(substr, int_str, base_from, base_size));
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base != "" && base[i] != '\0')
		i++;
	if (i < 2)
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
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_from_size;
	int		base_to_size;
	int		num;
	char	*res;

	if (check_base(base_from_size) || check_base(base_to_size))
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

int	main(void)
{
	char	*str;
	char	*base_from;
	char	*base_to;
	char	*out_str;

	str = "-200";
	base_from = "0123456789abcdef";
	base_to = "0123456789";
	out_str = ft_convert_base(str, base_from, base_to);
	printf("Test 1: %s\n", out_str);
}
/*
// 	str = "-115";
// 	base_from = "0123456789abcdef";
// 	base_to = "0123456789";
// 	out_str = ft_convert_base(str, base_from, base_to);
// 	printf("Test 1: %s\n", out_str);
// 	str = "7fffffff";
// 	base_from = "0123456789abcdef";
// 	base_to = "01";
// 	out_str = ft_convert_base(str, base_from, base_to);
// 	printf("Test 2: %s\n", out_str);
// 	str = "---5478773671";
// 	base_from = "012345678";
// 	base_to = "0123456789abcdef";
// 	out_str = ft_convert_base(str, base_from, base_to);
// 	printf("Test 3: %s\n", out_str);
// 	str = "---1000+";
// 	base_from = "01";
// 	base_to = "0123456789";
// 	out_str = ft_convert_base(str, base_from, base_to);
// 	printf("Test 4: %s\n", out_str);
// 	free(out_str);
// 	return (0);
	*/