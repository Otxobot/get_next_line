
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
	int count;

	count = 0;
	while (s[count] != c)
		count++;
	return(count);
}
