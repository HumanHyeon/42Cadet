#include "libft.h"

size_t	ft_strlen(char const *s)
{
	size_t index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}
