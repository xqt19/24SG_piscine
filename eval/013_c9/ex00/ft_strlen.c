/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yilau <yilau@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:23:43 by yilau             #+#    #+#             */
/*   Updated: 2025/03/04 16:03:43 by yilau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

/*
include <stdio.h>

int	main(void)
{
	char	string1[] = "abufu12345";
	char	string2[] = "!@ #$^&*()-+";
	char	string3[50] = "123";

	printf("the length of \"%s\": %d\n", string1, ft_strlen(string1));
	printf("the length of \"%s\": %d\n", string2, ft_strlen(string2));
	printf("the length of \"%s\": %d\n", string3, ft_strlen(string3));
	return (0);
}
*/