/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehypark <sehypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 01:32:28 by sehypark          #+#    #+#             */
/*   Updated: 2021/05/31 01:32:29 by sehypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *cur;
	t_list *next;

	cur = *lst;
	while (cur != NULL)
	{
		next = cur->next;
		del(cur->content);
		free(cur);
		cur = next;
	}
	*lst = NULL;
}
