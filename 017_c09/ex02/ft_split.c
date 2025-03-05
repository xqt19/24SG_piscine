/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 20:24:24 by xitan             #+#    #+#             */
/*   Updated: 2025/03/03 21:46:27 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*get_str(char *src, int i, int len)
{
	int		j;
	char	*str;

	str = (char *)malloc((sizeof(char) * len) + 1);
	if (str == NULL)
		return (NULL);
	j = 0;
	while (j < len)
		str[j++] = src[i++];
	str[j] = '\0';
	return (str);
}

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	wordcount(char *str, char *charset)
{
	int	i;
	int	wordcount;

	i = 0;
	wordcount = 0;
	if (!is_sep(str[i], charset) && str[i] != '\0')
		wordcount++;
	i++;
	while (str[i] != '\0')
	{
		if (!(is_sep(str[i], charset)) && is_sep(str[i - 1], charset))
			wordcount++;
		i++;
	}
	return (wordcount);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	res = (char **)malloc(sizeof(char *) * (wordcount(str, charset) + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (!(is_sep(str[i + j], charset)) && (str[i + j] != '\0'))
			j++;
		if (j > 0)
		{
			res[k++] = get_str(str, i, j);
			i += (j - 1);
		}
		i++;
	}
	res[k] = NULL;
	return (res);
}

// int	main()
// {
// 	char *str;
// 	char *charset;
// 	char **outarr;

// 	str = "-!!hel+lo w@#orld!";
// 	charset = "+-!@#";
// 	outarr = ft_split(str, charset);
// 	for (int i=0; outarr[i] != NULL; i++)
// 		printf("%s\n", outarr[i]);
// }
