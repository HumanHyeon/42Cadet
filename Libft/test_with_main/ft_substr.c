/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehypark <sehypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 15:17:08 by sehypark          #+#    #+#             */
/*   Updated: 2021/05/04 16:23:05 by sehypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char const *s)
{
	size_t index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

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
	while (s[i])
	{
		if (j != len)
			str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

#include <stdio.h>

int		main()
{
	char s[] = "abcde12345";
	unsigned int start =100;
	size_t len = 100;
	char *re;

	re = ft_substr(s, start, len);
	printf("%s\n", re);
}
