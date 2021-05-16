/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehypark <sehypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:14:51 by sehypark          #+#    #+#             */
/*   Updated: 2021/05/16 17:14:52 by sehypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t return_value;

	if (!dst || !src)
		return (0);
	return_value = ft_strlen(src);
	if (dstsize > 0)
	{
		i = 0;
		while(src[i] != '\0')
		{
			if (i == (dstsize - 1))
				break ;
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (return_value);
}