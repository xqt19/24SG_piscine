/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:47:21 by xitan             #+#    #+#             */
/*   Updated: 2025/02/27 21:26:08 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	size;

	size = 0;
	while (to_find[size] != '\0')
		size++;
	if (size == 0)
		return (str);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (to_find[j] == str[i])
		{
			j++;
			if (j == size)
				return (&str[i - j + 1]);
		}
		else
			j = 0;
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char str1[] = "hello";
// 	char str2[] = "l";
// 	printf("%s\n", "---strstr---");
// 	if (strstr(str1,str2) != NULL)
// 		printf("%s\n", strstr(str1,str2));
// 	else
// 		printf("%s\n", "It is Null!");
// 	printf("%s\n", "---ft_strstr---");
// 	if (ft_strstr(str1,str2) != NULL)
// 		printf("%s\n", ft_strstr(str1,str2));
// 	else
// 		printf("%s\n", "It is Null!");
// }