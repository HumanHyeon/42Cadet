/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehypark <sehypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:37:00 by sehypark          #+#    #+#             */
/*   Updated: 2021/05/30 22:37:02 by sehypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list) * 1)))
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
