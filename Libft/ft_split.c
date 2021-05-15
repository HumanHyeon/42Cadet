/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehypark <sehypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:52:07 by sehypark          #+#    #+#             */
/*   Updated: 2021/04/10 09:58:18 by sehypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_sperator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (true);
		i++;
	}
	return (false);
}

static int		count_word(char *str, char *charset)
{
	int		count;
	bool	check;
	int		i;

	count = 0;
	check = false;
	i = 0;
	while (str[i] != '\0')
	{
		if (!is_sperator(str[i], charset) && !check)
		{
			check = true;
			count++;
		}
		else if (is_sperator(str[i], charset))
			check = false;
		i++;
	}
	return (count);
}

static int		find_nextword_location(char *str, char *charset, int *offset)
{
	int	index;
	int	length;

	index = *offset;
	length = 0;
	while (str[index] != '\0')
	{
		if (!is_sperator(str[index], charset))
			break ;
		index++;
	}
	*offset = index;
	while (str[index] != '\0')
	{
		if (is_sperator(str[index], charset))
			break ;
		length++;
		index++;
	}
	return (length);
}

static char	*make_word(char *str, int *offset, int length)
{
	char	*word;
	int		i;

	i = 0;
	word = (char*)malloc(sizeof(char) * (length + 1));
	while (i < length)
	{
		word[i] = str[*offset + i];
		i++;
	}
	word[i] = '\0';
	*offset = *offset + length;
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**dic;
	int		offset;
	int		word;
	int		i;
	int		length;

	word = count_word(str, charset);
	if ((dic = (char**)malloc(sizeof(char*) * (word + 1))) == NULL)
		return (NULL);
	i = 0;
	offset = 0;
	while (i < word)
	{
		length = find_nextword_location(str, charset, &offset);
		dic[i] = make_word(str, &offset, length);
		i++;
	}
	dic[i] = NULL;
	return (dic);
}
