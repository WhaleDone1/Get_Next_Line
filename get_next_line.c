/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:06:11 by bcarpent          #+#    #+#             */
/*   Updated: 2024/02/28 22:08:36 by barpent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static char *ft_get_buffer(char *stash, char *buffer)
{
	char *tmp;

	tmp = ft_strjoin(stash, buffer);
	free(stash);
	return (tmp);
}

static char *ft_next_line(char *stash)
{
	int i;
	int j;
	char *line;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	line = ft_calloc((ft_strlen(stash) - i + 1), sizeof(char));
	if (!line)
		return (NULL);
	i++;
	while (stash[i])
		line[j++] = stash[i++];
	free(stash);
	return (line);
}

static char *ft_get_line(char *stash)
{
	char *line;
	int i;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] && stash[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char *read_file(int fd, char *stash)
{
	char *buffer;
	int read_count;

	if (!stash)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	read_count = BUFFER_SIZE;
	while (read_count > 0)
	{
		read_count = read(fd, buffer, BUFFER_SIZE);
		if (read_count == -1)
		{
			return (free(buffer), NULL);
		}
		buffer[read_count] = 0;
		stash = ft_get_buffer(stash, buffer);
		if (ft_strchrn(buffer))
			break;
	}
	return (free(buffer), stash);
}

char *get_next_line(int fd)
{
	static char *stash;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
		stash = ft_calloc(1, 1);
	stash = read_file(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_next_line(stash);
	return (line);
}