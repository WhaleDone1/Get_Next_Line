/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcarpent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:22:37 by bcarpent          #+#    #+#             */
/*   Updated: 2024/02/28 14:20:32 by bcarpent         ###   ########.fr       */
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
	int	i;

	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
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

int	ft_strchrn(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	int		n;
	char	*str;

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
