/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:09:35 by bcarpent          #+#    #+#             */
/*   Updated: 2024/02/28 22:03:33 by barpent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

size_t ft_strlen(const char *theString);
char *get_next_line(int fd);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strchrn(char *buffer);
void *ft_calloc(size_t elementCount, size_t elementSize);

#endif

#ifndef BUFFER_SIZE

#define BUFFER_SIZE 10

#endif