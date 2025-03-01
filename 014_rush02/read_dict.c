/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xitan <xitan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 19:36:20 by xitan             #+#    #+#             */
/*   Updated: 2025/03/01 21:43:29 by xitan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*read_dict(char *file)
{
	size_t buffer;
	ssize_t bytes_read;
	size_t total_read;
	int	fd;
	char *content;

	fd = open (file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buffer = 1024;
	content = (char *)malloc(buffer);
	if (content == NULL)
		return NULL; 
	while ((bytes_read = read(fd, content + total_read,
		buffer - total_read))> 0)
	{
		total_read += bytes_read;
		if (total_read == buffer) {
            buffer *= 2;
            content = (char *)realloc(content, buffer);
            if (content == NULL) 
                return (NULL);
        }
	}
	if (bytes_read == -1) {
        free(content);
        close(fd);
        return (NULL);
    }
	content[total_read] = '\0';
	close(fd);
	return (content);
}

int main() {
    char *filename = "numbers.dict";
    char *str = read_dict(filename);
	int i;

    if (str) {
		i = 0;
        while (str[i] != '\0')
			i++;
        write(1, str, i);

        // Free the allocated memory
        free(str);
    }

    return 0;
}