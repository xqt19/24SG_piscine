/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:40:13 by xitan             #+#    #+#             */
/*   Updated: 2025/02/28 15:19:07 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_build_res(char **strs, int size, char *res, char *sep)
{
	int	i;
	int	j;
	int	total;
	int	k;

	i = 0;
	total = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			res[total++] = strs[i][j++];
		k = 0;
		if (i != size - 1)
		{
			while (sep[k] != '\0')
				res[total++] = sep[k++];
		}
		i++;
	}
	res[total] = '\0';
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total;
	int		i;
	char	*res;

	if (size <= 0)
	{
		res = (char *) malloc (1);
		if (res == NULL)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	total = 0;
	i = 0;
	while (i < size)
	{
		total += ft_strlen(strs[i++]);
		if (i != size - 1)
			total += ft_strlen(sep);
	}
	res = (char *)malloc(total + 1);
	if (res == NULL)
		return (NULL);
	return (ft_build_res(strs, size, res, sep));
}

// #include <stdio.h>
// int	main()
// {
// 	char *strs[] = {"hello", "wORLd", "everyone", 
// "firstword", "secondword", "thirdword"};
// 	char sep[] = "-*-";
// 	int size = 6;

// 	char *res = ft_strjoin(size, strs, sep);
// 	if (res == NULL)
// 		printf("%s\n","It is null!");
// 	else
// 		printf("%s\n",res);
// }
