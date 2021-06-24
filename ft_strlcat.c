/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehypark <sehypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:47:43 by sehypark          #+#    #+#             */
/*   Updated: 2021/05/16 16:47:44 by sehypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
