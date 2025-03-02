/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochen <jochen@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 01:41:00 by jochen            #+#    #+#             */
/*   Updated: 2025/03/02 19:46:36 by jochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	put_str(char *s)
{
	while (*s != '\0')
		write(1, s++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*slice_str(char *s, int start, int end)
{
	char	*ptr;
	int		i;

	ptr = malloc((end - start + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*join3(char *s1, char *s2, char *s3)
{
	int		out_size;
	char	*out;
	char	*ptr;

	out_size = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1;
	out = malloc(out_size * sizeof(char));
	ptr = out;
	while (*s1 != '\0')
		*ptr++ = *s1++;
	while (*s2 != '\0')
		*ptr++ = *s2++;
	while (*s3 != '\0')
		*ptr++ = *s3++;
	*ptr = '\0';
	return (out);
}

char	*h_compose(char *base[1000], int n, char *h_postfix)
{
	int		h_div;
	int		h_mod;
	char	*h_str;
	char	*full_str;

	h_div = n / 100;
	h_mod = n % 100;
	h_str = join3(base[h_div], " ", h_postfix);
	if (h_mod == 0)
		return (h_str);
	full_str = join3(h_str, " and ", base[h_mod]);
	free(h_str);
	return (full_str);
}
