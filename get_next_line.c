/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:18:11 by abasante          #+#    #+#             */
/*   Updated: 2023/01/12 16:51:40 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_line(char *save) 
{
	char	*line;
	int		i;

	i = 0;
	// if no line return NULL
	if (!save[i])
		return (NULL);
	// go to the eol
	while (save[i] && save[i] != '\n')
		i++;
	// malloc to eol
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	// line = buffer
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	// if eol is \0 or \n, replace eol by \n
	if (save[i] && save[i] == '\n')
		line[i++] = '\n';
	return (line);
}
 
char *ft_save(char *save)
{
	// printf("save: %s\n",save);
	// printf("------------------------");
    int i;
    char *str;
    for (i = 0; save[i] && save[i] != '\n'; i++);
    if (!save[i])
    {
        free(save);
        return NULL;
    }
    // Allocate a new string for the remaining part of the save string
    str = malloc(ft_strlen(save + 1) + 1);
	//printf("len: %zu\n", ft_strlen(save + i + 1));
    if (!str)
        return NULL;
    // Copy the remaining part of the save string into str and add a null terminator
    ft_strlcpy(str, save + i + 1, ft_strlen(save + i + 1) + 1);
    // Free the memory allocated to save and set it to NULL
    free(save);
    save = NULL;
    // Return the new string
    return str;
}

char	*ft_read_and_save(int fd, char *save)
{
	char	*buff;
	int		read_bytes;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		//printf("save: %s\n",save);
		//printf("read_bytes: %d\n",read_bytes);
		read_bytes = read(fd, buff, BUFFER_SIZE);
		// printf("read_bytes: %d\n", read_bytes);
		if (read_bytes == -1)
		{
			free(buff);
			buff = NULL;
			return (NULL);
		}
		// printf("save: %s\n",save);
		// printf("buff: %s\n", buff);
		buff[read_bytes] = '\0';
		save = ft_strjoin(save, buff);
		// printf("save: %s\n",save);
	}
	free(buff);
	buff = NULL;
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		printf("Error buffer size is less than %d\n", BUFFER_SIZE);
		return (0);
	}
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
