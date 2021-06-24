/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehypark <sehypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:17:08 by sehypark          #+#    #+#             */
/*   Updated: 2021/05/18 02:17:40 by sehypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	size = ft_strlen(s) - start;
	if (len < size)
		size = len;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
