/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:55:37 by xitan             #+#    #+#             */
/*   Updated: 2025/02/19 18:55:37 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

//post-review TODO: strlcopy should return size of dest+src
// #include <stdio.h>
// int main()
// {
// 	char dest[40];
// 	char src[] = "helloworld";
// 	printf("%d\n", ft_strlcpy(dest, src, 5));
// 	printf("%s\n", dest);
// }