/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordify.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochen <jochen@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:42:17 by jochen            #+#    #+#             */
/*   Updated: 2025/03/02 20:45:18 by hyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_and_put(char *numstr, char *base[1000], char *units[13]);
int		put_in_words(char *numstr, char *base[1000], char *units[13], int len);
void	put_conjunction(int len, int triplet_unit);
void	put_triplet_unit(char *s, int len, char *units[13]);
int		parse_slice(char *number, int size);
void	put_str(char *s);
int		ft_strlen(char *str);

int	check_and_put(char *numstr, char *base[1000], char *units[13])
{
	int	len;

	len = ft_strlen(numstr);
	if (len > 39)
		return (0);
	put_in_words(numstr, base, units, len);
	return (1);
}

int	put_in_words(char *numstr, char *base[1000], char *units[13], int len)
{
	int	slice_size;
	int	has_printed;
	int	slice_value;

	has_printed = 0;
	while (len > 0)
	{
		slice_size = ((len - 1) % 3) + 1;
		slice_value = parse_slice(numstr, slice_size);
		if (slice_value > 0)
		{
			if (has_printed)
				put_conjunction(len, slice_value);
			put_triplet_unit(base[slice_value], len, units);
			has_printed = 1;
		}
		len -= slice_size;
		numstr += slice_size;
	}
	if (!has_printed)
		put_str(base[0]);
	put_str("\n");
	return (1);
}

void	put_conjunction(int len, int triplet_unit)
{
	if (len <= 3 && triplet_unit < 100)
		put_str(" and ");
	else
		put_str(", ");
}

void	put_triplet_unit(char *s, int len, char *units[13])
{
	put_str(s);
	if (len > 3)
	{
		put_str(" ");
		put_str(units[(len - 1) / 3]);
	}
}

int	parse_slice(char *number, int size)
{
	int	result;

	result = 0;
	while (*number != '\0' && size > 0)
	{
		result = result * 10 + (int)(*number - '0');
		number++;
		size--;
	}
	return (result);
}
