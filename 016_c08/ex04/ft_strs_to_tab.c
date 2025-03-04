/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:18:09 by xitan             #+#    #+#             */
/*   Updated: 2025/03/04 17:18:09 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_stock_str.h"

char	*ft_strdup(char *str)
{
	char	*res;
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	res = (char *)malloc((i + 1) * (sizeof(char)));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arr;
	int			i;
	int			j;

	arr = (t_stock_str *) malloc(sizeof(t_stock_str) * (ac + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
			j++;
		arr[i].size = j;
		arr[i].str = ft_strdup(av[i]);
		arr[i].copy = ft_strdup(av[i]);
		if (arr[i].str == NULL || arr[i].copy == NULL)
			return (NULL);
		i++;
	}
	arr[i].str = NULL;
	return (arr);
}

// int	main()
// {
// 	char str1[] = "he11o";
// 	char str2[] = "wor1d!";
// 	char str3[] = "123456";
// 	char *av[] = {str1,str2,str3};
// 	int	ac = 3;

// 	t_stock_str *arr = ft_strs_to_tab(ac, av);
// 	int i = 0;
// 	while (arr[i].str != NULL)
// 	{
// 		printf("%d\n", arr[i].size);
// 		printf("%s\n", arr[i].str);
// 		printf("%s\n", arr[i].copy);
// 		i++;
// 	}
// }
