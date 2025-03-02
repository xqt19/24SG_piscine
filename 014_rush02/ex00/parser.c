/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochen <jochen@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:45:45 by hyan              #+#    #+#             */
/*   Updated: 2025/03/02 19:44:54 by jochen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		parse_file(char *filename, char *base[1000], char *units[13]);
char	**read_lines(char *filename);
int		is_valid_lines(char **lines);
int		is_valid_line(char *line);
char	*strip_collapse_spaces(char *s);
int		populate(char **lines, char *base_numbers[1000], char *units[13]);
void	put_str(char *s);

char	*strip_collapse_spaces(char *s)
{
	int	read_idx;
	int	write_idx;

	read_idx = 0;
	write_idx = 0;
	while (s[read_idx] == ' ')
		read_idx++;
	while (s[read_idx] != '\0')
	{
		if (s[read_idx] == ' '
			&& (s[read_idx - 1] == ' ' || s[read_idx - 1] == ':'))
		{
			read_idx++;
			continue ;
		}
		s[write_idx++] = s[read_idx++];
	}
	if (write_idx > 0 && s[write_idx - 1] == ' ')
		write_idx--;
	s[write_idx] = '\0';
	return (s);
}

void	remove_empty_lines(char **lines)
{
	int	read_idx;
	int	write_idx;

	read_idx = 0;
	write_idx = 0;
	while (lines[read_idx] != NULL)
	{
		if (*lines[read_idx] == '\0')
			free(lines[read_idx]);
		else
			lines[write_idx++] = lines[read_idx];
		read_idx++;
	}
	lines[write_idx] = NULL;
}

int	is_valid_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i] != NULL)
	{
		if (!is_valid_line(lines[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_line(char *line)
{
	if (!('0' <= *line && *line <= '9'))
		return (0);
	while (*line != '\0' && '0' <= *line && *line <= '9')
		line++;
	line = strip_collapse_spaces(line);
	if (*line++ != ':')
		return (0);
	while (32 <= *line && *line <= 126)
		line++;
	return (*line == '\0');
}

int	parse_file(char *filename, char *base[1000], char *units[13])
{
	char	**lines;
	int		i;
	int		is_success;

	lines = read_lines(filename);
	if (lines == NULL)
		return (0);
	remove_empty_lines(lines);
	is_success = is_valid_lines(lines);
	is_success = is_success && populate(lines, base, units);
	i = 0;
	while (lines[i] != NULL)
		free(lines[i++]);
	free(lines);
	return (is_success);
}
