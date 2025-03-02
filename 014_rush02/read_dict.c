/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:36:20 by xitan             #+#    #+#             */
/*   Updated: 2025/03/02 14:14:27 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*read_file(int fd, char *content, size_t buffer, size_t total_read)
{
	ssize_t	bytes_read;
	char	*content2;
	size_t	i;

	bytes_read = read(fd, content, buffer);
	while (bytes_read > 0)
	{
		total_read += bytes_read;
		if (total_read == buffer)
		{
			buffer *= 2;
			content2 = (char *)malloc(buffer);
			if (content2 == NULL)
				return (NULL);
			i = -1;
			while (++i < total_read)
				content2[i] = content[i];
			free (content);
			content = content2;
		}
		bytes_read = read(fd, content + total_read, buffer - total_read);
	}
	if (bytes_read == -1)
		return (NULL);
	return (content);
}

char	*read_dict(char *file)
{
	size_t	buffer;
	int		fd;
	char	*content;
	int		i;

	fd = open (file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buffer = 1024;
	content = (char *)malloc(buffer);
	if (content == NULL)
		return (NULL);
	content = read_file(fd, content, buffer, 0);
	if (content == NULL)
		return (NULL);
	i = 0;
	while (content[i] != '\0')
		i++;
	content[i] = '\0';
	close(fd);
	return (content);
}

int	main(void)
{
	char	*filename;
	char	*str;
	int		i;

	filename = "numbers.dict";
	str = read_dict(filename);
	if (str)
	{
		i = 0;
		while (str[i] != '\0')
			i++;
		write(1, str, i);
		free(str);
	}
	return (0);
}
