/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehypark <sehypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:06:58 by sehypark          #+#    #+#             */
/*   Updated: 2021/05/18 01:16:33 by sehypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' ||\
				c == '\f');
}

int			ft_atoi(const char *str)
{
	unsigned long long	result;
	bool				sign;
	size_t				i;

	result = 0;
	sign = false;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = true;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (((result > LONG_MAX) && !sign) || ((result > (LONG_MAX - 1)) && sign))
		return (sign ? 0 : -1);
	if (sign)
		return ((int)result * -1);
	return ((int)result);
}
