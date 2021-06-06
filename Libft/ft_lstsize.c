/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehypark <sehypark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 22:48:34 by sehypark          #+#    #+#             */
/*   Updated: 2021/05/30 22:48:38 by sehypark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int lstsize;

	lstsize = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		lstsize++;
	}
	return (lstsize);
}
