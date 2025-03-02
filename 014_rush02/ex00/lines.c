/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochen <jochen@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:46:46 by jochen            #+#    #+#             */
/*   Updated: 2025/03/02 20:14:45 by hyan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*slice_str(char *s, int start, int end);

int	count_lines(char *s)
{
	int	num_lines;

	num_lines = 1;
	while (*s != '\0')
	{
		if (*s == '\n')
			num_lines++;
		s++;
	}
	return (num_lines);
}

char	**split_lines(char *s)
{
	int		i;
	int		j;
	int		line_i;
	char	**lines;

	lines = malloc((count_lines(s) + 1) * sizeof(char *));
	if (!lines)
		return (NULL);
	i = 0;
	line_i = 0;
	while (s[i] != '\0')
	{
		j = i;
		while (s[j] != '\0' && s[j] != '\n')
			j++;
		lines[line_i++] = slice_str(s, i, j);
		i = j + (s[j] == '\n');
	}
	lines[line_i] = NULL;
	return (lines);
}
