/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:06:11 by bcarpent          #+#    #+#             */
/*   Updated: 2024/02/28 12:21:26 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_join_and_free(char *stash, char *buffer)
{
	char *tmp;
	if (!buffer)
		return (stash);
	tmp = ft_strjoin(stash, buffer);
	free(stash);
	return (tmp);
}

static char	*read_file(int fd, char *stash)
{
	int		count_bytes;
	char	*buffer;

	count_bytes = BUFFER_SIZE;
	stash = NULL;
	if (buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char)) == NULL);
		return (NULL);
	while (count_bytes > 0)
	{
		count_bytes = read(fd, buffer, BUFFER_SIZE);
		if (count_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[count_bytes] = 0;
		stash = ft_join_and_free(stash, buffer);
		if (ft_strchr(buffer, '\n') == 1)
			break;
			
	}
	free(buffer);
	return(stash);
}

static char	*stash_to_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (line = ft_calloc(i + 2, sizeof(char)) == NULL)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*next_line(char *stash)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (tmp = ft_calloc(ft_strlen(stash) - (i + 1)) == NULL)
		return (NULL);
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	while (stash[i])
	{
		tmp[j] = stash[i];
		i++;
		j++;
	}
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char 	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if(!stash)
		stash = read_file(fd, stash);
	line = stash_to_line(stash);
	stash = next_line(stash);
	return (line);
}
