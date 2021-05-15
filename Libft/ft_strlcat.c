#include "libft.h"

size_t	ft_strlen(char const *s)
{
	size_t index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dst_len;
	size_t src_len;
	size_t i;
	size_t j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	j = dst_len;
	if (dstsize > 0 && dst_len < dstsize - 1)
	{
		while (src[i] && dst_len + i < dstsize - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	if (dst_len >= dstsize)
		dst_len = dstsize;
	return (src_len + dst_len);
}

// #include <stdio.h>
// #include <string.h>

// int main()
// {
// 	char dst[16];
// 	dst[15] = 0;
// 	memset(dst, 'r', 15);

// 	char src[] = "lorem ipsum dolor sit amet";
// 	printf("%zu\n", ft_strlcat(dst, src, 5));
// }
