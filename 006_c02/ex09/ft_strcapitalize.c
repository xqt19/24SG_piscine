/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:31:55 by xitan             #+#    #+#             */
/*   Updated: 2025/02/19 18:31:55 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_new_word(char *str, int i)
{
	return (i == -1 || (str[i] == ' ') || (str[i] == '+') || (str[i] == '-'));
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_new_word(str, i - 1) && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		else if (!ft_is_new_word(str, i - 1) && str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

// #include <stdio.h>
// int main()
// {
// 	char src[] = 
// 	"salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
// 	char src2[] = 
// 	"Salut, CoMMent tu vas ? 42mots Quarante-Deux; Cinquante+Et+Un";
// 	printf("%s\n", ft_strcapitalize(src));
// 	printf("%s\n", ft_strcapitalize(src2));
// }