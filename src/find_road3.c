/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_road3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:55:35 by aleveque          #+#    #+#             */
/*   Updated: 2017/03/28 19:52:41 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

t_list	*lst_att(t_all all, int type)
{
	t_list *tmp;

	tmp = all.sol;
	while (tmp != NULL && tmp->type != type)
		tmp = tmp->next;
	return (tmp);
}

t_all	associate(t_all all)
{
	t_list	*tmp;

	tmp = all.box;
	while (tmp != NULL)
	{
		if (tmp->type == 1)
			all.strat = ft_strdup(tmp->name);
		if (tmp->type == 2)
			all.end = ft_strdup(tmp->name);
		tmp = tmp->next;
	}
	if (all.strat == NULL || all.end == NULL)
	{
		ft_printf("ERROR: malloc\n");
		exit(3);
	}
	return (all);
}
