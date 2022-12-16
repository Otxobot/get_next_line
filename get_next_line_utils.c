/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:33:49 by abasante          #+#    #+#             */
/*   Updated: 2022/12/16 13:06:49 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t count;

	count = 0;
	if (!str)
		return(0);
	while(*str != '\0')
	{
		count++;
	}
	return(count);
}

char	*strchr(const char *s, int c)
{
	char	*chr;

	chr = (char *)s;
	while (*chr != (char)c)
	{
		if (!*chr)
			return (0);
		chr++;
	}
	return (chr);
}

char	*strjoin(const char *s1, const char *s2)
{
	unsigned int y1;
	unsigned int y2;
	unsigned int i;
	unsigned int x;
	char	*str1;

	y1 = ft_strlen((char *)s1);
	y2 = ft_strlen((char *)s2);
	i = 0;
	x = -1;

	str1 = malloc(sizeof(char) * (y1 + y2 + 1));
	if (!str1)
		return (0);
	while (*s1)
	{
		str1[i] = s1[i];
		i++;
	}
	while (s2[++x])
		str1[i++] =  s2[x];
	str1[i] = '\0';
	return (str1);
}

char	*ft_strdup(const char *s1)
{
	int		cont;
	char	*s1_new;
	int		size;

	size = ft_strlen (s1);
	s1_new = malloc (sizeof(char) * size + 1);
	if (!s1_new)
		return (0);
	cont = 0;
	while (s1[cont] != '\0')
	{
		s1_new[cont] = s1[cont];
		cont++;
	}
	s1_new[cont] = s1[cont];
	return (s1_new);
}
