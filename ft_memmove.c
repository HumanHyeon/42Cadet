/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehypark <sehypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:44:04 by sehypark          #+#    #+#             */
/*   Updated: 2021/05/15 17:57:30 by sehypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	if (dest == src || n == 0)
		return (dest);
	if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			*(unsigned char*)(dest + i - 1) = *(unsigned char*)(src + i - 1);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			*(unsigned char*)(dest + i) = *(unsigned char*)(src + i);
			i++;
		}
	}
	return (dest);
}
