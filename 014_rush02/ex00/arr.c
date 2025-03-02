/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochen <jochen@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:59:40 by jochen            #+#    #+#             */
/*   Updated: 2025/03/02 16:45:08 by jochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	null_arr(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		arr[i++] = NULL;
}

void	free_arr(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] != NULL)
			free(arr[i]);
		i++;
	}
}
