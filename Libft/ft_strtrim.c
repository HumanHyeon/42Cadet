/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehypark <sehypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 22:05:10 by sehypark          #+#    #+#             */
/*   Updated: 2021/05/28 22:05:11 by sehypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	size_t	i;

	if (!(str = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t front;
	size_t back;

	if (!s1 || !set)
		return (NULL);
	if (ft_strlen(s1) == 0 || ft_strlen(set) == 0)
		return ((char *)s1);
	front = 0;
	while (s1[front])
	{
		if (!(ft_strchr(set, s1[front])))
			break ;
		front++;
	}
	back = ft_strlen(s1) - 1;
	while (back >= front)
	{
		if (!(ft_strchr(set, s1[back])))
			break ;
		back--;
	}
	return (ft_strndup(s1 + front, back - front + 1));
}
