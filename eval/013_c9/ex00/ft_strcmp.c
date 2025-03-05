/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilau <yilau@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:09:01 by yilau             #+#    #+#             */
/*   Updated: 2025/03/04 16:03:53 by yilau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	index;

	index = 0;
	while (*(s1 + index) != '\0' || *(s2 + index) != '\0')
	{
		if (*(s1 + index) != *(s2 + index))
		{
			return (*(s1 + index) - *(s2 + index));
		}
		index++;
	}
	return (0);
}

/* 
#include <stdio.h>

int	main(void)
{
	char	str1[] = "abcde123s";
	char	str2[] = "abcde123b";
	int		diff;

	diff = ft_strcmp(str1, str2);
	printf("Result: %d\n", diff);
	return (0);
}
 */