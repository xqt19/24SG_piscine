/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:52:18 by bralee            #+#    #+#             */
/*   Updated: 2025/03/01 20:56:06 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	**ft_split(char *str, char *charset);
int		wd_count(char *str, char *charset);
int		is_sep(char c, char *cset);
char	*ft_strdup_mod(char *src, int idx, int size);

int	main(void)
{
	char	*str;
	char	*charset;
	char	**fin_str;
	int		i;
	int		j;

	str = "     Ths a trmph@It's-hrd@-to#ovrst my+stsfctn.  a";
	// str = "abc";
	charset = "+-!@# ";
	fin_str = ft_split(str, charset);
	i = 0;
	while (fin_str[i] != NULL)
	{
		j = 0;
		while (fin_str[i][j] != '\0')
		{
			write(1, &fin_str[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		free(fin_str[i]);
		i++;
	}
	free(fin_str);
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	char	**fin_str;
	int		idx;
	int		wlen;
	int		j;

	idx = 0;
	j = 0;
	fin_str = (char **)malloc(sizeof(char *) * (wd_count(str, charset) + 1));
	if (fin_str == NULL)
		return (NULL);
	while (str[idx] != '\0')
	{
		wlen = 0;
		while (!(is_sep(str[idx + wlen], charset)) && (str[idx + wlen] != '\0'))
			wlen++;
		if (wlen > 0)
		{
			fin_str[j] = ft_strdup_mod(str, idx, wlen);
			j++;
			idx = idx + wlen - 1;
		}
		idx++;
	}
	fin_str[j] = NULL;
	return (fin_str);
}

int	wd_count(char *str, char *cset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!(is_sep(str[i], cset)) && (str[i] != '\0'))
		count++;
	i++;
	while (str[i] != '\0')
	{
		if (!(is_sep(str[i], cset)) && is_sep(str[i - 1], cset))
			count++;
		i++;
	}
	return (count);
}

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup_mod(char *src, int idx, int size)
{
	int		i;
	char	*dup;

	dup = (char *)malloc((sizeof(char) * size) + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup[i] = src[idx];
		idx++;
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
