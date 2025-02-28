/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:17:21 by xitan             #+#    #+#             */
/*   Updated: 2025/02/27 22:03:01 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*copy;

	len = 0;
	while (src[len])
		len++;
	copy = (char *) malloc((len + 1) * (sizeof(char)));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

// #include <stdio.h>
// int	main()
// {
// 	char str[] = "helloworld";
// 	char *str1 = ft_strdup(str);
// 	if (str1 != NULL)
// 	{
// 		printf("str0: %s\n", str);
// 		printf("str1: %s\n", str1);
// 	}
// }