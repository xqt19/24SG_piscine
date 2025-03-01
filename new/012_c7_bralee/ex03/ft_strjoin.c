/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bralee <bralee@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:51:38 by bralee            #+#    #+#             */
/*   Updated: 2025/03/01 19:03:11 by bralee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include <unistd.h>
// #include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_buildstr(int size, char **strs, char *sep);
int		ft_total_len(int size, char **strs, char *sep);
char	*ft_strcat(char *dest, char *src);
int		ft_strlen(char *str);

// int	main(void)
// {
// 	char	*str1;
// 	char	*sep;
// 	int		i;
// 	char	*strs[] = {"ABC", "123", "[aaaaaaaaaaa]"};

// 	sep = "-!-";
// 	str1 = ft_strjoin(3, strs, sep);
// 	printf("%p", str1);
// 	i = 0;
// 	while (str1[i] != '\0')
// 	{
// 		write(1, &str1[i], 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// 	free(str1);
// 	i = 0;
// 	while (str1[i] != '\0')
// 	{
// 		write(1, &str1[i], 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*total_str;

	if (size <= 0)
	{
		total_str = (char *)malloc(sizeof(char) * 1);
		if (total_str == NULL)
			return (NULL);
		total_str[0] = '\0';
		return (total_str);
	}
	else
	{
		total_str = ft_buildstr(size, strs, sep);
	}
	return (total_str);
}

char	*ft_buildstr(int size, char **strs, char *sep)
{
	int		total_len;
	char	*total_str;
	int		i;

	total_len = 0;
	total_len = ft_total_len(size, strs, sep);
	total_str = (char *)malloc(sizeof(char) * (total_len + 1));
	if (total_str == NULL)
		return (NULL);
	total_str[0] = '\0';
	i = 0;
	while (i < size)
	{
		total_str = ft_strcat(total_str, strs[i]);
		if (i != (size - 1))
			total_str = ft_strcat(total_str, sep);
		i++;
	}
	return (total_str);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	i;
	int	total_len;

	i = 0;
	total_len = 0;
	while (i < size)
	{
		total_len = total_len + ft_strlen(strs[i]);
		if (i != (size - 1))
			total_len = total_len + ft_strlen(sep);
		i++;
	}
	return (total_len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
