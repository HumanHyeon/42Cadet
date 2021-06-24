/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehypark <sehypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 17:59:09 by sehypark          #+#    #+#             */
/*   Updated: 2021/06/15 17:59:10 by sehypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	freeall(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static	int		count_word(char const *str, char c)
{
	int		count;
	bool	check;
	int		i;

	count = 0;
	check = false;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && !check)
		{
			check = true;
			count++;
		}
		else if (str[i] == c)
			check = false;
		i++;
	}
	return (count);
}

static	int		find_index(char const *s, char c, int index)
{
	if (index == 0)
	{
		while (s[index] == c)
			index++;
		return (index);
	}
	while (s[index] != '\0')
	{
		if (s[index] == c)
			break;
		index++;
	}
	return (index);
}

static	char	*make_word(char const *s, char c, int index)
{
	char	*word;
	int		until;
	int		i;

	if (index != 0)
		index++;
	until = index;
	while (s[until] != '\0')
	{
		if (s[until] == c)
			break;
		until++;
	}
	if(!(word = (char *)malloc(sizeof(char *) * (until - index + 1))))
		return (NULL);
	i = 0;
	while (i < until - index + 1)
	{
		word[i] = s[index + i];
		i++;
	}
	word[until - index + 1] = '\0';
	return (word);
}

char			**ft_split(char const *s, char c)
{
	char	**str;
	int		count;
	int		index;
	int		i;

	count = count_word(s, c);
	if(!(str = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	i = 0;
	while (i <= count)
	{
		str[i] = NULL;
		i++;
	}
	index = 0;
	i = 0;
	while (i < count)
	{
		index = find_index(s, c, index);
		str[i] = make_word(s, c, index);
		if (str[i] == NULL)
		{
			freeall(str);
			return (NULL);
		}
		index++;
		i++;
	}
	return (str);
}
