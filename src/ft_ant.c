/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ant.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:55:46 by aleveque          #+#    #+#             */
/*   Updated: 2017/03/27 16:02:02 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		ft_sol_len(t_list *sol)
{
	int	i;

	i = -1;
	while (sol != NULL)
	{
		i++;
		sol = sol->next;
	}
	return (i);
}

t_all	check_sol(t_all all)
{
	t_list	*tmp;

	tmp = all.result;
	while (tmp->status == 0 && tmp != NULL)
	{
		tmp = tmp->next;
	}
	if (all.ant_nbr < (ft_sol_len(tmp) - ft_sol_len(tmp->next)) *
			(all.result->status - tmp->status))
	{
		tmp->status = 0;
		all = check_sol(all);
	}
	return (all);
}

t_all	ft_init_ant(t_all all)
{
	t_list		*tmp;

	tmp = all.result;
	while (tmp != NULL && all.ant_nbr >= all.ant)
	{
		if (tmp->status > 0)
		{
			all = ft_write(all.ant, lst_at_sol(tmp->type, all)->pipe->name
					, all);
			all.ant++;
		}
		tmp = tmp->next;
	}
	return (all);
}

t_all	ft_trav(t_all all)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		ant;

	tmp = all.result;
	while (tmp->status == 0 && tmp != NULL)
		tmp = tmp->next;
	tmp2 = tmp;
	while (tmp2 != NULL)
	{
		tmp = lst_at_sol(tmp2->type, all)->pipe;
		while (tmp != NULL)
		{
			if (lst_at(all, tmp->name)->status > 0)
			{
				ant = lst_at(all, tmp->name)->status;
				all = ft_write(ant, tmp->pipe->name, all);
				lst_at(all, tmp->name)->status = 0;
			}
			tmp = tmp->pipe;
		}
		tmp2 = tmp2->next;
	}
	return (all);
}

t_all	ft_ant(t_all all)
{
	all.ant_end = 0;
	all.ant = 1;
	all.bol = 0;
	all = ft_nbrsol(all);
	while (all.ant_nbr != all.ant_end)
	{
		all = check_sol(all);
		all = ft_init_ant(all);
		all = ft_trav(all);
		all = initiate(all);
	}
	return (all);
}
