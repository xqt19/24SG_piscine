/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:51:10 by xitan             #+#    #+#             */
/*   Updated: 2025/02/23 17:04:16 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i + 1 <= n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	else if (s1[i] == '\0' && s2[i] != '\0')
		return (0 - s2[i]);
	else if (s1[i] != '\0' && s2[i] == '\0')
		return (s1[i]);
	return (0);
}

int	main()
{
	char s1[20] = "helloworld";
	char s2[20] = "hellowor";

	printf("%d", ft_strncmp(s1,s2,8));
	printf("%d", strncmp(s1,s2,8));
}