/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:33:44 by abasante          #+#    #+#             */
/*   Updated: 2022/12/13 14:04:29 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *line)
{
	int		i;
	char	*s;

	if (!*line)
		return (NULL);
	while (*line && line[i] != '\n')
	i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		s[i] = line[i];
		i++;
	}
	
}











/*
char *get_next_line(int fd)
{
}
*/