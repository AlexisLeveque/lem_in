/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:17:23 by aleveque          #+#    #+#             */
/*   Updated: 2016/12/06 16:19:35 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *next;

	if (!(new = f(lst)))
		return (NULL);
	next = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(new->next = f(lst)))
			return (NULL);
		new = new->next;
	}
	return (next);
}
