/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochen <jochen@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 01:41:00 by jochen            #+#    #+#             */
/*   Updated: 2025/03/02 22:02:39 by hyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		parse_file(char *filename, char *base[1000], char *units[13]);
void	null_arr(char **arr, int size);
void	free_arr(char **arr, int size);
int		check_and_put(char *number, char *base[1000], char *units[13]);
char	*get_valid_positive_int(char *str);
int		clean_up(int err_val, char *s, char *base[1000], char *units[13]);

int	main(int argc, char *argv[])
{
	char	*filename;
	char	*number;
	char	*base_numbers[1000];
	char	*units[13];

	null_arr(base_numbers, 1000);
	null_arr(units, 13);
	if (argc < 2 || argc > 3)
		return (clean_up(1, "Error\n", base_numbers, units));
	if (argc == 2)
	{
		filename = "numbers.dict";
		number = get_valid_positive_int(argv[1]);
	}
	else
	{
		filename = argv[1];
		number = get_valid_positive_int(argv[2]);
	}
	if (number == NULL)
		return (clean_up(1, "Error\n", base_numbers, units));
	if (!parse_file(filename, base_numbers, units)
		|| !check_and_put(number, base_numbers, units))
		return (clean_up(1, "Dict Error\n", base_numbers, units));
	return (clean_up(0, "", base_numbers, units));
}

char	*get_valid_positive_int(char *str)
{
	int		sign;
	char	*result;

	sign = 1;
	while (*str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	if (sign == -1)
		return (NULL);
	if (!('0' <= *str && *str <= '9'))
		return (NULL);
	while (*str == '0')
		str++;
	result = str;
	while (*str != '\0')
	{
		if (!('0' <= *str && *str <= '9'))
			return (NULL);
		str++;
	}
	return (result);
}

int	clean_up(int err_val, char *s, char *base[1000], char *units[13])
{
	free_arr(base, 1000);
	free_arr(units, 13);
	while (*s != '\0')
		write(1, s++, 1);
	return (err_val);
}
