/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:09:35 by bcarpent          #+#    #+#             */
/*   Updated: 2024/02/28 18:03:14 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

size_t	ft_strlen(const char *str);
int     ft_strchrn(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char    *ft_strcpy(char *src, char *dest);
char    *get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
