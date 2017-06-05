/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:36:55 by aleveque          #+#    #+#             */
/*   Updated: 2017/03/31 15:27:30 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

t_list		*lst_at(t_all all, char *name)
{
	t_list *tmp;

	tmp = all.box;
	while (tmp != NULL && ft_strcmp(name, tmp->name) != 0)
		tmp = tmp->next;
	return (tmp);
}

t_all		ft_lied(char *name1, char *name2, t_all all)
{
	t_list *tmp;
	t_list *tmp2;
	t_list *tmp3;

	if ((tmp = lst_at(all, name1)) == NULL)
		all.retour = -2;
	if ((tmp2 = lst_at(all, name2)) == NULL)
		all.retour = -2;
	if (all.retour == -2)
		return (all);
	tmp3 = tmp->pipe;
	ft_lstadd(&tmp->pipe, ft_lstnew(tmp2->name, 0));
	tmp3 = tmp2->pipe;
	ft_lstadd(&tmp2->pipe, ft_lstnew(tmp->name, 0));
	return (all);
}

t_all		order_enter(t_all all, char *line)
{
	if (all.phase == 0)
	{
		if ((all.ant_nbr = ft_atoi(line)) <= 0)
			all.retour = -1;
		all.phase = 1;
	}
	else if (all.phase == 1)
	{
		all = phase1(all, line, 0);
	}
	if (all.phase == 2)
	{
		all = ft_error_pipes(line, all);
		all.split = ft_strsplit(line, '-');
		if (ft_tablen(all.split) == 2)
			all = ft_lied(all.split[0], all.split[1], all);
		else
			all.retour = 1;
		ft_freetab(all.split);
	}
	return (all);
}

t_all		get_enter(t_all all)
{
	char	*line;

	all.phase = 0;
	while (get_next_line(0, &line) > 0)
	{
		if (!(all.retour < 0 || all.retour == 1))
		{
			if (line[0] == 'L')
				all.retour = -2;
			if (line[0] == '#' && line[1] == '#')
			{
				all.box_type = 0;
				if (ft_strcmp(&line[2], "start") == 0)
					all.box_type = 1;
				else if (ft_strcmp(&line[2], "end") == 0)
					all.box_type = 2;
			}
			else if (line[0] != '#')
				all = order_enter(all, line);
			if (all.retour != 1)
				ft_lstaddend(&all.enter, ft_lstnew(line, 0));
		}
		all = ft_count(all, line);
	}
	return (all);
}

int			main(void)
{
	t_all	all;

	all.retour = 0;
	all.count = 0;
	all.box_type = 0;
	all.result = NULL;
	all.box = NULL;
	all.enter = NULL;
	all = get_enter(all);
	if (ft_error(all) < 0)
		return (-1);
	all = list_road(all);
	all = find_road(all);
	if (all.retour < 0)
		if (ft_error(all) < 0)
		{
			ft_leaks2(all);
			return (-1);
		}
	print_enter(all);
	all = ft_ant(all);
	ft_leaks(all);
	return (0);
}
