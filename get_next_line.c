/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <bcarpent@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:21:12 by bcarpent          #+#    #+#             */
/*   Updated: 2024/02/28 10:34:15 by bcarpent         ###   ########.fr       */
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
	//free(stash);
	return (tmp);
}

static char	*read_file(int fd, char *stash)
{
	int		count_char;
	char	*buffer;

	count_char = BUFFER_SIZE;
	stash = NULL;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	//if (!buffer)
	//	return (NULL);
	while (count_char > 0)
	{
		count_char = read(fd, buffer, BUFFER_SIZE);
		//if (count_char == 0)
		//	break;
		if (count_char == -1)
		{
			//free(buffer);
			return (NULL);
		}
		buffer[count_char] = 0;
		stash = ft_free(stash, buffer);
	}
	//free(buffer);
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
	//if (!line)
	//	return (NULL);
	while (j <= i)
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
	//if (stash[i] != '\0')
		i++; //n'etait pas dans le if avant
	//else
	//{
	//	free(stash);
	//	return (NULL);
	//}
	tmp = ft_calloc(ft_strlen(stash) - i + 1, sizeof(char));
	//if (!tmp)
	//	return (NULL);
	while (stash[i])
	{
		tmp[j] = stash[i];
		i++;
		j++;
	}
	//free(stash);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = read_file(fd, stash);
	line = get_line(stash);
	stash = remove_line(stash);
	return (line);
}



/*int main(){

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
}*/
