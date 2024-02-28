/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barpent <barpent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:22:37 by bcarpent          #+#    #+#             */
/*   Updated: 2024/02/28 22:03:31 by barpent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	int sizetotal;
	int i;
	int j;
	char *str;

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

char *ft_strchrn(char *buffer)
{
	char *str;

	str = (char *)buffer;
	while (*str != '\0' && *str != '\n')
		str++;
	if (*str == '\n')
		return (str);
	return (NULL);
}

void *ft_calloc(size_t count, size_t size)
{
	int i;
	int n;
	char *str;

	i = 0;
	n = (size * count);
	str = malloc(n);
	if (!str)
		return (NULL);
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}