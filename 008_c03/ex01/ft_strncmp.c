/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:51:10 by xitan             #+#    #+#             */
/*   Updated: 2025/02/27 19:50:03 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n || (s1[i] == '\0' && s2[i] == '\0'))
		return (0);
	return (s1[i] - s2[i]);
}

// #include <stdio.h>
// int	main()
// {
// 	char str1[] = "helloworld";
// 	char str2[] = "helloworld";
// 	unsigned int n = 5;
// 	printf("%d\n", ft_strncmp(str1,str2, n));
// }