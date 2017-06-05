/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ant2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:41:44 by aleveque          #+#    #+#             */
/*   Updated: 2017/03/27 16:02:07 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

t_all	ft_nbrsol(t_all all)
{
	t_list	*tmp;

	tmp = all.result;
	all.nbr_sol = 0;
	while (tmp != NULL)
	{
		all.nbr_sol++;
		tmp->status = all.nbr_sol;
		tmp = tmp->next;
	}
	return (all);
}

t_list	*lst_at_sol(int type, t_all all)
{
	t_list	*tmp;

	tmp = all.sol;
	while (tmp != NULL && tmp->type != type)
		tmp = tmp->next;
	return (tmp);
}

t_all	ft_print(int nbr, char *name, t_all all)
{
	if (all.bol == 1)
		ft_printf(" ");
	all.bol = 1;
	ft_printf("L%d-%s", nbr, name);
	return (all);
}

t_all	ft_write(int nbr, char *name, t_all all)
{
	t_list	*tmp;

	if (ft_strcmp(name, all.end) != 0)
	{
		tmp = lst_at(all, name);
		tmp->move = nbr;
	}
	else
	{
		if (all.bol == 1)
			ft_printf(" ");
		all.bol = 1;
		ft_printf("L%d-%s", nbr, name);
		all.ant_end++;
	}
	return (all);
}

t_all	initiate(t_all all)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = all.box;
	while (tmp != NULL)
	{
		if (tmp->move != 0)
		{
			all = ft_print(tmp->move, tmp->name, all);
			tmp->status = tmp->move;
			tmp->move = 0;
		}
		tmp = tmp->next;
	}
	all.bol = 0;
	ft_printf("\n");
	return (all);
}
