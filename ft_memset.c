/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehypark <sehypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:27:00 by sehypark          #+#    #+#             */
/*   Updated: 2021/05/15 16:27:02 by sehypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		value = (unsigned char)value;
		*((unsigned char*)(ptr + i)) = value;
		i++;
	}
	return (ptr);
}
