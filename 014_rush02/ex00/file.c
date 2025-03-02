/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochen <jochen@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 01:41:00 by jochen            #+#    #+#             */
/*   Updated: 2025/03/02 19:52:42 by jochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	**read_lines(char *filename);
int		get_file_size(char *filename);
char	*read_content(char *filename, char *content, int size);
char	**split_lines(char *s);

char	**read_lines(char *filename)
{
	int		filesize;
	char	*filecontent;
	char	**lines;

	filesize = get_file_size(filename);
	filecontent = malloc(filesize * sizeof(char));
	if (!filecontent)
		return (NULL);
	filecontent = read_content(filename, filecontent, filesize);
	if (filecontent == NULL)
	{
		free(filecontent);
		return (NULL);
	}
	lines = split_lines(filecontent);
	free(filecontent);
	if (lines == NULL)
		return (NULL);
	return (lines);
}

int	get_file_size(char *filename)
{
	int		fd;
	char	*buffer;
	int		bytes_read;
	int		file_size;

	buffer = malloc(512 * sizeof(char));
	if (buffer == NULL)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (-1);
	}
	file_size = 0;
	bytes_read = read(fd, buffer, 512 * sizeof(char));
	while (bytes_read > 0)
	{
		file_size += bytes_read;
		bytes_read = read(fd, buffer, 512 * sizeof(char));
	}
	close(fd);
	free(buffer);
	return (file_size);
}

char	*read_content(char *filename, char *content, int size)
{
	int					fd;
	long unsigned int	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	bytes_read = read(fd, content, size * sizeof(char));
	close(fd);
	if (bytes_read != size * sizeof(char))
		return (NULL);
	return (content);
}
