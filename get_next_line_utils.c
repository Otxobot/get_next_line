
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
			return (NULL);
		chr++;
	}
	return (chr);
}
