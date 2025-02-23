/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:29:48 by xitan             #+#    #+#             */
/*   Updated: 2025/02/23 16:50:31 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] == '\0' && s2[i] != '\0')
		return (0 - s2[i]);
	else if (s1[i] != '\0' && s2[i] == '\0')
		return (s1[i]);
	return (0);
}

int	main()
{
	char s1[20] = "helloworld";
	char s2[20] = "hel@lowor";

	printf("%d", ft_strcmp(s1,s2));
	printf("%d", strcmp(s1,s2));
}