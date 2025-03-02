/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochen <jochen@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:45:45 by hyan              #+#    #+#             */
/*   Updated: 2025/03/02 19:23:15 by jochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		populate(char **lines, char *base[1000], char *units[13]);
void	populate_single(char *line, char *base[1000], char *units[13]);
void	populate_arr_idx_value(char **arr, int idx, char *value);
int		parse_int(char *c);
int		ft_strlen(char *str);
int		interpolate_base(char *base[1000]);
char	*join3(char *s1, char *s2, char *s3);
char	*h_compose(char *base[1000], int n, char *h_postfix);

int	populate(char **lines, char *base_numbers[1000], char *units[13])
{
	int	i;

	i = 0;
	while (lines[i] != NULL)
	{
		populate_single(lines[i], base_numbers, units);
		i++;
	}
	if (!interpolate_base(base_numbers))
		return (0);
	return (1);
}

void	populate_single(char *line, char *base[1000], char *units[13])
{
	int	num_length;
	int	num_idx;
	int	num_zeroes;

	num_length = 0;
	num_zeroes = 0;
	while (line[num_length] != ':')
	{
		if (line[num_length] == '0')
			num_zeroes++;
		num_length++;
	}
	if (num_length < 4)
	{
		num_idx = parse_int(line);
		populate_arr_idx_value(base, num_idx, line + num_length + 1);
	}
	else if (line[0] == '1'
		&& num_zeroes + 1 == num_length && num_zeroes % 3 == 0)
	{
		num_idx = num_zeroes / 3;
		populate_arr_idx_value(units, num_idx, line + num_length + 1);
	}
}

void	populate_arr_idx_value(char **arr, int idx, char *value)
{
	char	*str;

	str = malloc((ft_strlen(value) + 1) * sizeof(char));
	arr[idx] = str;
	while (*value != '\0')
		*str++ = *value++;
	*str = '\0';
}

int	parse_int(char *c)
{
	int	result;

	result = 0;
	while ('0' <= *c && *c <= '9')
	{
		result = result * 10 + (int)(*c - '0');
		c++;
	}
	return (result);
}

int	interpolate_base(char *base[1000])
{
	int		i;
	char	*h_postfix;

	h_postfix = base[100];
	if (h_postfix == NULL)
		return (0);
	i = 0;
	while (i < 21)
	{
		if (base[i] == NULL || base[(i % 10) * 10] == NULL)
			return (0);
		i++;
	}
	while (i < 100)
	{
		if (i % 10 != 0)
			base[i] = join3(base[(i / 10) * 10], "-", base[i % 10]);
		i++;
	}
	while (i < 1000)
	{
		base[i] = h_compose(base, i, h_postfix);
		i++;
	}
	return (1);
}
