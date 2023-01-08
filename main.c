#include "get_next_line.h"

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Error: No se ha especificado un archivo: (%d)\n", argc);
        return (1);
    }
    int fd = open(argv[1], O_RDONLY);
    char *line;
    if(fd < 0)
    {
        printf("Error: unable to open file: (%d)\n", fd);
        return 1;
    }
    while((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
        line = NULL; /* NULL */
    }
    close(fd);
    return (0);
}
