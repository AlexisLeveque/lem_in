/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:40:09 by aleveque          #+#    #+#             */
/*   Updated: 2017/03/28 19:39:51 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>
#include <stdlib.h>

t_list	*ft_lstnew(char *name, int type)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->name = ft_strdup(name);
	if (new->name == NULL)
		return (NULL);
	new->type = type;
	new->status = 0;
	new->move = 0;
	new->pipe = NULL;
	new->next = NULL;
	return (new);
}
