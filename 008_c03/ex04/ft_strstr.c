/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:47:21 by xitan             #+#    #+#             */
/*   Updated: 2025/02/23 18:42:47 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	size;

	while (to_find[size] != '\0')
	{
		size++;
	}
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

int	main()
{
	char s1[40] = "hellollpworld";
	char s2[20] = "llp";

    char *res0 = ft_strstr(s1,s2);
    if (res0 == NULL)
        printf("NULL!\n");
    else
	    printf("%s\n", res0);
    char *res = strstr(s1,s2);
    if (res == NULL)
        printf("NULL!\n");
    else
	    printf("%s\n", res);
}