/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bralee <bralee@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:47:26 by bralee            #+#    #+#             */
/*   Updated: 2025/02/18 13:47:48 by bralee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		check_invalid(char *base);
int		ft_m_atoi(char *str, char *base_from, int base_val);
int		base_conv(char *trun, char int_str[], char *base_from, int base_val);
int		valid_value(char ch, char *base_from);
void	ft_m_itoa(char *new_nbr, int value, char *base_to, int base_to_val);

// int	main(void)
// {
// 	char	*str;
// 	char	*base_from;
// 	char	*base_to;
// 	char	*out_str;

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
// }

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_from_val;
	int		base_to_val;
	int		value;
	char	*new_nbr;

	if (check_invalid(base_from) || check_invalid(base_to))
		return (0);
	base_from_val = 0;
	while (base_from[base_from_val] != '\0')
		base_from_val++;
	base_to_val = 0;
	while (base_to[base_to_val] != '\0')
		base_to_val++;
	value = 0;
	value = ft_m_atoi(nbr, base_from, base_from_val);
	new_nbr = (char *)malloc((sizeof(char)) * 33);
	ft_m_itoa(new_nbr, value, base_to, base_to_val);
	return (new_nbr);
}

int	check_invalid(char *base)
{
	int	m;
	int	n;

	m = 0;
	if ((base == 0) || (base[0] == '\0') || (base[1] == '\0'))
		return (1);
	while (base[m] != '\0')
	{
		if (base[m] == 43 || base[m] == 45)
			return (1);
		if (((base[m] >= 9) && (base[m] <= 13)) || base[m] == 32)
			return (1);
		n = m + 1;
		while (base[n] != '\0')
		{
			if (base[m] == base[n])
				return (1);
			n++;
		}
		m++;
	}
	return (0);
}

int	ft_m_atoi(char *str, char *base_from, int base_val)
{
	int		idx;
	int		sign_count;
	char	*trun;
	char	int_str[999];

	idx = 0;
	while (((str[idx] >= 9) && (str[idx] <= 13)) || str[idx] == 32)
		idx++;
	sign_count = 0;
	while ((str[idx] == 43) || (str[idx] == 45))
	{
		if (str[idx] == 45)
			sign_count++;
		idx++;
	}
	trun = &str[idx];
	if (sign_count % 2)
		return (-1 * base_conv(trun, int_str, base_from, base_val));
	return (base_conv(trun, int_str, base_from, base_val));
}

int	base_conv(char *trun, char int_str[], char *base_from, int base_val)
{
	int				i;
	int				base_idx;
	unsigned int	value;

	i = 0;
	while (trun[i] != '\0' && valid_value(trun[i], base_from))
	{
		base_idx = 0;
		while (base_from[base_idx] != '\0')
		{
			if (trun[i] == base_from[base_idx])
				int_str[i] = base_idx + '0';
			base_idx++;
		}
		i++;
	}
	int_str[i] = '\0';
	i = 0;
	value = 0;
	while (int_str[i] != '\0')
	{
		value = (value * base_val) + (int_str[i] - '0');
		i++;
	}
	return (value);
}

int	valid_value(char ch, char *base)
{
	int	idx;

	idx = 0;
	while (base[idx] != '\0')
	{
		if (ch == base[idx])
			return (1);
		idx++;
	}
	return (0);
}
