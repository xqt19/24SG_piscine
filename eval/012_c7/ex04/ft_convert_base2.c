/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bralee <bralee@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:52:08 by bralee            #+#    #+#             */
/*   Updated: 2025/02/25 15:52:09 by bralee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_m_itoa(char *new_nbr, int value, char *base_to, int base_to_val);
int		convert_value(int value, int sign);
void	base_send(char *new_nbr, char *base_to, int size);
void	ft_rev_char_tab(char *tab, int size, int sign);
void	ft_swap(char *a, char *b);

void	ft_m_itoa(char *new_nbr, int value, char *base_to, int base_to_val)
{
	int				i;
	int				sign;
	int				size;
	unsigned int	new_value;

	sign = 0;
	if (value < 0)
		sign = 1;
	new_value = convert_value(value, sign);
	i = 0;
	while (new_value != 0)
	{
		new_nbr[i] = (new_value % base_to_val) + '0';
		new_value = new_value / base_to_val;
		i++;
	}
	if (i == 0)
	{
		new_nbr[i] = '0';
		i++;
	}
	size = i;
	base_send(new_nbr, base_to, size);
	ft_rev_char_tab(new_nbr, size, sign);
	return ;
}

int	convert_value(int value, int sign)
{
	if (sign)
		value = (-1) * value;
	return (value);
}

void	base_send(char *new_nbr, char *base_to, int size)
{
	int	i;
	int	idx;

	i = 0;
	idx = 0;
	while (i < size)
	{
		idx = new_nbr[i] - '0';
		new_nbr[i] = base_to[(idx)];
		i++;
	}
	return ;
}

void	ft_rev_char_tab(char *tab, int size, int sign)
{
	int	m;

	m = 0;
	if (sign)
	{
		tab[size] = '-';
		size++;
	}
	while (m < size / 2)
	{
		ft_swap(&tab[m], &tab[(size - m) - 1]);
		m++;
	}
	return ;
}

void	ft_swap(char *a, char *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
