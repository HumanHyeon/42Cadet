/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehypark <sehypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 23:18:05 by sehypark          #+#    #+#             */
/*   Updated: 2021/05/28 23:18:07 by sehypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int n)
{
	size_t n_size;

	n_size = (n < 0 ? 1 : 0);
	while (n)
	{
		n_size++;
		n /= 10;
	}
	return (n_size);
}

static char		*ft_strrev(char *str)
{
	size_t	i;
	size_t	str_size;
	char	tmp;

	i = 0;
	str_size = ft_strlen(str);
	while (i < str_size / 2)
	{
		tmp = str[i];
		str[i] = str[str_size - i - 1];
		str[str_size - i - 1] = tmp;
		i++;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	bool	sign;
	size_t	n_size;
	size_t	i;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	n_size = get_size(n);
	if (!(str = (char *)malloc(sizeof(char) * (n_size + 1))))
		return (NULL);
	sign = (n < 0 ? true : false);
	if (sign)
		n = -n;
	i = 0;
	while (i < n_size)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	if (sign)
		str[i - 1] = '-';
	return (ft_strrev(str));
}
