/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:00:02 by aleveque          #+#    #+#             */
/*   Updated: 2017/03/31 15:09:26 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

t_all	phase1(t_all all, char *line, int i)
{
	char	*name;

	all.split = ft_strsplit(line, ' ');
	while (all.split[i] != NULL)
		i++;
	if (i < 3)
		all.phase = 2;
	else
	{
		if (DIGIT(all.split[i - 1]) == 0 || DIGIT(all.split[i - 2]) == 0)
			all.retour = -6;
		else
		{
			if ((name = get_name(line)) == NULL)
			{
				all.retour = -7;
				return (all);
			}
			ft_lstadd(&all.box, ft_lstnew(name, all.box_type));
			free(name);
		}
	}
	ft_freetab(all.split);
	all.box_type = 0;
	return (all);
}

t_all	ft_count(t_all all, char *line)
{
	free(line);
	all.count++;
	if (all.count > 1000)
		all.retour = -5;
	return (all);
}

t_all	is_in_list(t_all all, char *name)
{
	t_list *tmp;

	tmp = all.box;
	while (tmp != NULL)
	{
		if (ft_strcmp(name, tmp->name) == 0 && all.phase != 2)
			all.retour = -4;
		tmp = tmp->next;
	}
	return (all);
}

int		ft_error2(t_all all)
{
	t_list	*tmp;
	int		s;
	int		e;

	s = 0;
	e = 0;
	tmp = all.box;
	while (tmp != NULL)
	{
		if (tmp->type == 1)
			s++;
		if (tmp->type == 2)
			e++;
		tmp = tmp->next;
	}
	if (s != 1 || e != 1)
	{
		ft_printf("ERROR:start/end\n");
		return (-1);
	}
	return (0);
}

int		ft_error(t_all all)
{
	if (all.retour < 0 || all.phase == 0)
	{
		if (all.phase == 0)
			write(1, "ERROR\n", 6);
		if (all.retour == -1)
			ft_printf("ERROR:ant nbr\n");
		if (all.retour == -2)
			ft_printf("ERROR:pipe\n");
		if (all.retour == -3)
			ft_printf("ERROR:insoluble\n");
		if (all.retour == -4)
			ft_printf("ERROR:multiple room\n");
		if (all.retour == -5)
			ft_printf("ERROR:too many line\n");
		if (all.retour == -6)
			ft_printf("ERROR:coordonee\n");
		return (-1);
	}
	return (ft_error2(all));
}
