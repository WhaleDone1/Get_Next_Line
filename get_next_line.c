/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <bcarpent@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:21:12 by bcarpent          #+#    #+#             */
/*   Updated: 2024/02/27 12:49:23 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static char	*ft_free(char *stash, char *buffer)
{
	char	*tmp;

	if (!buffer)
		return (stash);
	if (!stash)
		return (ft_strcpy(buffer, stash));
	tmp = ft_strjoin(stash, buffer);
	return (tmp);
}

static char	*read_file(int fd, char *stash)
{
	int		count_char;
	char	*buffer;

	count_char = BUFFER_SIZE;
	stash = NULL;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (count_char > 0)
	{
		count_char = read(fd, buffer, BUFFER_SIZE);
		if (count_char == -1)
			return (NULL);
		buffer[count_char] = 0;
		stash = ft_free(stash, buffer);
	}
	return (stash);
}

static char	*get_line(char *stash)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	return (line);
}

char	*remove_line(char *stash)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	tmp = ft_calloc(ft_strlen(stash) - i + 1, sizeof(char));
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
	static char	*stash;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//if (!stash)
	stash = read_file(fd, stash);
	/*line = get_line(stash);
	stash = remove_line(stash);
	*/
	printf("%s", stash);
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
	if (fd < 1)
		return (0);
	printf("%c", 'a');

    char *s;
     s = get_next_line(fd);
     /*printf("[%s]", s);
     s = get_next_line(fd);
     printf("[%s]", s);
     s = get_next_line(fd);
     printf("[%s]", s);*/

    /*s = get_next_line(fd);
    printf("[%s]", s);
    free(s);
    while (s)
    {
        s = get_next_line(fd);
        printf("[%s]", s);    
        free(s);
    }*/
    close(fd);
}
