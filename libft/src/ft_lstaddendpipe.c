/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddendpipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 18:15:12 by aleveque          #+#    #+#             */
/*   Updated: 2017/03/27 14:48:30 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstaddendpipe(t_list **lst, t_list *new)
{
	t_list *tmp;

	tmp = *lst;
	if (new != NULL)
	{
		if (tmp != NULL)
		{
			while (tmp->pipe != NULL)
				tmp = tmp->pipe;
			tmp->pipe = new;
		}
		else
			*lst = new;
	}
}
