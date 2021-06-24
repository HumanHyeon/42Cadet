/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehypark <sehypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:52:07 by sehypark          #+#    #+#             */
/*   Updated: 2021/05/18 01:11:53 by sehypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**freeall(char **str, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
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

static	int		find_nextword_location(char const *str, char c, int *offset)
{
	int	index;
	int	length;

	index = *offset;
	length = 0;
	while (str[index] != '\0')
	{
		if (str[index] != c)
			break ;
		index++;
	}
	*offset = index;
	while (str[index] != '\0')
	{
		if (str[index] == c)
			break ;
		length++;
		index++;
	}
	return (length);
}

static	char	*make_word(char const *str, int *offset, int length)
{
	char	*word;
	int		i;

	i = 0;
	if (!(word = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (i < length)
	{
		word[i] = str[*offset + i];
		i++;
	}
	word[i] = '\0';
	*offset = *offset + length;
	return (word);
}

char			**ft_split(char const *s, char c)
{
	char	**dic;
	int		offset;
	int		word;
	int		i;
	int		length;

	if (s == NULL)
		return (NULL);
	word = count_word(s, c);
	if ((dic = (char**)malloc(sizeof(char*) * (word + 1))) == NULL)
		return (NULL);
	i = 0;
	offset = 0;
	while (i < word)
	{
		length = find_nextword_location(s, c, &offset);
		dic[i] = make_word(s, &offset, length);
		if (dic[i] == NULL)
			return (freeall(dic, i));
		i++;
	}
	dic[i] = NULL;
	return (dic);
}
