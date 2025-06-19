/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_to_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gro-donn <gro-donn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 07:33:21 by gro-donn          #+#    #+#             */
/*   Updated: 2025/01/29 21:46:39 by gro-donn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define BUFFSIZE 1024
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>

int	count_words(const char *line)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*line && *line != '\n')
	{
		if (*line != ' ' && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (*line == ' ')
		{
			in_word = 0;
		}
		line++;
	}
	return (count);
}

static void	handle_read_error(char *buff, int fd, const char *message)
{
	if (buff)
		free(buff);
	if (fd != -1)
		close(fd);
	handle_error(message);
}

static char	*resize_buffer(char *buff, int total, int new_size)
{
	char	*new_buffer;

	new_buffer = malloc(new_size);
	if (!new_buffer)
		handle_read_error(buff, -1, "Memory allocation error");
	memcpy(new_buffer, buff, total);
	free(buff);
	return (new_buffer);
}

char	*read_file_to_buffer(const char *filename)
{
	int		fd;
	char	*buff;
	int		total;
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	buff = malloc(BUFFSIZE + 1);
	if (fd == -1 || !buff)
		handle_read_error(buff, fd, "Error with fd or malloc");
	total = 0;
	while (1)
	{
		bytes_read = read(fd, buff + total, BUFFSIZE);
		if (bytes_read == -1)
			handle_read_error(buff, fd, "Error reading file");
		if (bytes_read == 0)
			break ;
		total += bytes_read;
		if (total + bytes_read > total)
			buff = resize_buffer(buff, total, total + BUFFSIZE + 1);
	}
	buff[total] = '\0';
	close(fd);
	return (buff);
}
