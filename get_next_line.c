/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:18:11 by abasante          #+#    #+#             */
/*   Updated: 2023/01/09 09:18:13 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_line(char *save) {
    char *newline = ft_strchr(save, '\n');
    if (!newline) {
        return NULL;
    }
	int length_of_line = newline - save;
    char *line = malloc(length_of_line);
    if (!line) {
        return NULL;
    }
    ft_memcpy(line, save, length_of_line);
    line[length_of_line] = '\n';
    line[length_of_line + 1] = '\0';
    return (line);
}

char *ft_save(char *save)
{
    int i;
    char *str;
    // Find the index of the first occurrence of a newline character
    for (i = 0; save[i] && save[i] != '\n'; i++);
    // If no newline character was found, free the memory allocated to save and return NULL
    if (!save[i])
    {
        free(save);
        return NULL;
    }
    // Allocate a new string for the remaining part of the save string
    str = malloc(ft_strlen(save + i + 1) + 1);
    if (!str)
        return NULL;
    // Copy the remaining part of the save string into s and add a null terminator
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
		//printf("-> %s\n", save);
		read_bytes = read(fd, buff, BUFFER_SIZE);
		//printf("-> %s\n", save);
		if (read_bytes == -1)
		{
			free(buff);
			buff = NULL; /* NULL */
			return (NULL);
		}

		/* 
		 * When buffer size is 1 the lines are read 1 char at a time:
		 * Uncomment to see how it works. Check different BUFFER_SIZEs
		*/

		//printf("-> %s\n", save);
		 //printf("--->buff: %s\n", buff);
		 //printf("read_bytes: %d\n", read_bytes);
		buff[read_bytes] = '\0';
		//printf("read_bytes: %d\n", read_bytes);
		//printf("buff: %s\n", buff);
		save = ft_strjoin(save, buff);
	}
	free(buff);
	buff = NULL; /* NULL */
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
