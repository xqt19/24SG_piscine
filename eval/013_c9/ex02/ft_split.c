/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilau <yilau@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:46:54 by yilau             #+#    #+#             */
/*   Updated: 2025/03/04 14:12:25 by yilau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_valid_sep(char c, char *charset)
{
	if (*charset == '\0')
		return (0);
	while (c != *charset && *charset != '\0')
		charset++;
	if (*charset != '\0')
		return (1);
	return (0);
}

int	ft_count_substr(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_valid_sep(str[i], charset))
		{
			if (i != 0 && !ft_is_valid_sep(str[i - 1], charset))
			{
				count++;
				while (ft_is_valid_sep(str[i], charset))
					i++;
				continue ;
			}
		}
		i++;
	}
	if (i != 0 && !ft_is_valid_sep(str[i - 1], charset))
		count++;
	return (count);
}

char	*ft_strndup(char *src, int n)
{
	char	*dest;

	if (n < 0)
		return (0);
	dest = (char *)malloc((n + 1) * sizeof(char));
	if (dest == 0)
		return (0);
	dest[n] = '\0';
	while (n > 0)
	{
		dest[n - 1] = src[n - 1];
		n--;
	}
	return (dest);
}

char	*ft_strdup_index(char *str, char *charset, int index)
{
	char	*substr;
	int		length;
	int		j;

	j = 0;
	while (index >= 0)
	{
		while (ft_is_valid_sep(str[j], charset) && str[j] != '\0')
			j++;
		length = 0;
		while (!ft_is_valid_sep(str[j], charset) && str[j] != '\0')
		{
			length++;
			j++;
		}
		index--;
	}
	substr = ft_strndup((str + j - length), length);
	if (substr == 0)
		return (0);
	return (substr);
}

char	**ft_split(char *str, char *charset)
{
	char	**sub_str;
	int		qty_substr;
	int		i;

	qty_substr = ft_count_substr(str, charset);
	sub_str = (char **)malloc((qty_substr + 1) * sizeof(char *));
	if (sub_str == 0)
		return (0);
	i = 0;
	while (i < qty_substr)
	{
		sub_str[i] = ft_strdup_index(str, charset, i);
		i++;
	}
	sub_str[qty_substr] = 0;
	return (sub_str);
}

/* 
#include <stdio.h>

int	main(void)
{
	char	string1[] = "20,000_Leagues; Under the Sea - by Jules_Verne";
	// char	string1[] = "";
	char	charset1[] = "; ,";
	// char	charset1[] = "";
	char	**arr;
	int		i;

	arr = ft_split(string1, charset1);
	if (arr == 0)
	{
		free(arr);
		return (-1);
	}
	printf("String to be splited: \"%s\"\n", string1);
	printf("Seperator: \"%s\"\n", charset1);
	i = 0;
	while (arr[i] != 0)
	{
		printf("Substring - %03d: \"%s\"\n", i, arr[i]);
		i++;
	}
	i = 0;
	while (arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
	free(arr);
	return (0);
}
 */