/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:06:11 by bcarpent          #+#    #+#             */
/*   Updated: 2024/02/28 15:29:54 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


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
	if ((buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char))) == NULL)
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
		if (!stash)
			stash = ft_strcpy(buffer, stash);
		else
			stash = ft_join_and_free(stash, buffer);
		if ((ft_strchrn(stash)) == 1 || !stash)
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
	if ((line = ft_calloc(i + 2, sizeof(char))) == NULL)
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
	if ((tmp = ft_calloc(ft_strlen(stash) - (i), sizeof(char))) == NULL)
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
	stash = read_file(fd, stash);
	line = stash_to_line(stash);
	stash = next_line(stash);
	return (line);
}

int main(){

    // printf("ret:%s\n",get_next_line(5));
    // printf("ret:%s\n",get_next_line(5));


    // char *s;
    // s = malloc(10);
    // printf("%p\n",s);
    // free_ptr((void **)(&s));
    // printf("%p\n",s);
    // s = NULL;
    // printf("%p\n",s);


    // char *s;
    // s = ft_strdup("abcdefghijklm");
    // printf("main: %p\n", s);
    // printf("%s", ft_substr(s, 100, 1000));
    // free_ptr((void **)(&s));

    int fd = open("testfile.txt", O_RDONLY);

    char *s;
     //s = get_next_line(fd);
     //printf("[%s]", s);
     //s = get_next_line(fd);
     //printf("[%s]", s);
     //s = get_next_line(fd);
     //printf("[%s]", s);


    s = get_next_line(fd);
    printf("[%s]", s);
    free(s);
    int i = 0;
    while (s && i < 15)
    {
        s = get_next_line(fd);
        printf("[%s]", s);
        free(s);
	i++;
    }
    close(fd);
}
