/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bralee <bralee@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:51:13 by bralee            #+#    #+#             */
/*   Updated: 2025/02/25 15:51:15 by bralee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src);

// int	main(void)
// {
// 	char	original[100] = "AAABBBCCC";
// 	char	*duplicate;

// 	duplicate = ft_strdup(original);
// 	printf("Original String: '%s'\n", original);
// 	printf("Duplicate string: '%s'\n", duplicate);
// 	printf("Dup Memory Address: '%p'\n", duplicate);
// 	free(duplicate);
// 	printf("Freed string: '%s'\n", duplicate);
// 	return (0);
// }

char	*ft_strdup(char *src)
{
	int		idx;
	int		src_len;
	char	*dup;

	idx = 0;
	while (src[idx] != '\0')
		idx++;
	src_len = idx;
	dup = (char *)malloc((sizeof(char) * src_len) + 1);
	if (dup == NULL)
		return (NULL);
	idx = 0;
	while (src[idx] != '\0')
	{
		dup[idx] = src[idx];
		idx++;
	}
	dup[idx] = '\0';
	return (dup);
}
