#include "libft.h"

void*	ft_memset(void *ptr, int value, size_t num)
{
	size_t i;

	if (!ptr)
		return (NULL);
	i = 0;
	while (i < num)
	{
		value = (unsigned char)value;
		*((unsigned char*)(ptr + i)) = value;
		i++;
	}
	return (ptr);
}
