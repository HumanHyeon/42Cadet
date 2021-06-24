/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehypark <sehypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:29:25 by sehypark          #+#    #+#             */
/*   Updated: 2021/05/15 16:29:25 by sehypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*(unsigned char*)(dest + i) = *(unsigned char*)(src + i);
		if ((unsigned char)c == *(unsigned char*)(src + i))
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
