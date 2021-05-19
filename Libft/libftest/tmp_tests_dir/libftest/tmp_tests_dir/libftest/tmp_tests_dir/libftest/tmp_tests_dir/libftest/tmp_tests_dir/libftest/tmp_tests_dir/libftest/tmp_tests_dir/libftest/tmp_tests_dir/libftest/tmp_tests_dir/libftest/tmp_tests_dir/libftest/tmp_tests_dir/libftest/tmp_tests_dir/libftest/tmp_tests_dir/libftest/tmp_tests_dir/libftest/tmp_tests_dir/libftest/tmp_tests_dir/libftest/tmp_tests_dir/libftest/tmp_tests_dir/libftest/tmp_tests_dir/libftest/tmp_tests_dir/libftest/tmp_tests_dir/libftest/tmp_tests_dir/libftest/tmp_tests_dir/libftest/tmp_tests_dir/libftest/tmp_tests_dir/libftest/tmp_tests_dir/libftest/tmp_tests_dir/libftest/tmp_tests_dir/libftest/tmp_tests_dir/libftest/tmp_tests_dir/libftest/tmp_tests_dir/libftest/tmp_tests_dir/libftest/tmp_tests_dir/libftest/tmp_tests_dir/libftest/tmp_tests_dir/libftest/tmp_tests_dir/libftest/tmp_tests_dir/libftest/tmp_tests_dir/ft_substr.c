/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehypark <sehypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:17:08 by sehypark          #+#    #+#             */
/*   Updated: 2021/05/18 01:37:24 by sehypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	allocate_size;
	size_t	i;
	size_t	j;
	char	*str;

	if (ft_strlen(s) <= start)
		return (NULL);
	allocate_size = ft_strlen(s) - start;
	if (allocate_size >= len)
		str = (char *)malloc(sizeof(char) * (len + 1));
	else
		str = (char *)malloc(sizeof(char) * (allocate_size + 1));
	if (str == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (j != len)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
