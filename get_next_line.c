/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abasante <abasante@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:33:44 by abasante          #+#    #+#             */
/*   Updated: 2022/12/16 13:05:48 by abasante         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *buffer;
    char *line;
    ssize_t nbytes;
    static char *aux;

    nbytes = 1;
    line = ft_strdup("");
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (0);
    while (!strchr(line, '\n') && nbytes != 0)
    {
        nbytes = read(fd, buffer, BUFFER_SIZE);
        if (nbytes < 0)
        {
            free (buffer);
            return(0);
        }
        buffer[nbytes] = '\0';
        line = strjoin(line, buffer);
    }


    int x = 0;
    
    while (line[x - 1] != '\n')
    {
        x++;
    }
    printf("%s\n", aux);
    aux = ft_strdup(&line[x]);
}

int main(void)
{
    int fd;
    char *str;

    fd = open("filetbr.txt", O_RDONLY);
    str = get_next_line(fd);
    printf("%s", str);
}
