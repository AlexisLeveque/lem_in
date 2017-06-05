/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_road.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:15:03 by aleveque          #+#    #+#             */
/*   Updated: 2017/03/27 16:02:33 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

t_all	add_sol(t_all all)
{
	t_list		*tmp;
	static int	i = 0;

	i++;
	tmp = all.road;
	ft_lstadd(&all.sol, ft_lstnew(all.start->name, i));
	tmp = tmp->next;
	while (tmp != NULL)
	{
		ft_lstaddendpipe(&all.sol, ft_lstnew(tmp->name, 0));
		tmp = tmp->next;
	}
	return (all);
}

int		in_list(char *name, t_list *start)
{
	t_list *tmp;

	tmp = start;
	while (tmp != NULL)
	{
		if (ft_strcmp(name, tmp->name) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		is_sol(t_all all)
{
	t_list *tmp;

	tmp = all.road;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp = lst_at(all, tmp->name);
		if (tmp->type == 2)
			return (1);
	}
	return (0);
}

t_all	recur_road(t_all all, t_list *curr)
{
	t_list *current;
	t_list *next;

	if (curr != NULL)
		current = lst_at(all, curr->name);
	else
		current = NULL;
	if (all.road == NULL)
		ft_lstadd(&all.road, ft_lstnew(all.start->name, 0));
	if (is_sol(all) == 1)
		all = add_sol(all);
	else if (current == NULL)
		return (all);
	else if (in_list(current->name, all.road) == 1)
		all = recur_road(all, curr->next);
	else
	{
		all = recur_road(all, curr->next);
		ft_lstaddend(&all.road, ft_lstnew(current->name, 0));
		all = recur_road(all, current->pipe);
		del_end(&all.road);
	}
	return (all);
}

t_all	list_road(t_all all)
{
	all.result_len = 0;
	all.start = all.box;
	all.road = NULL;
	while (all.start->type != 1)
		all.start = all.start->next;
	all = recur_road(all, all.start->pipe);
	del_end(&all.road);
	return (all);
}
