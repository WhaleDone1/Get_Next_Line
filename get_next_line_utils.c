/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:22:37 by bcarpent          #+#    #+#             */
/*   Updated: 2024/02/27 12:54:05 by bcarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizetotal;
	int		i;
	int		j;
	char	*str;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (sizetotal + 1));
	if (!str || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[sizetotal] = 0;
	return (str);
}

char	*ft_strcpy(char *src, char *dest)
{
	char	*tmp;
	int	i;

	tmp = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = malloc(size * count);
	if (!str)
		return (NULL);
	ft_bzero(str, size * count);
	return (str);
}
