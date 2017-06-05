/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_road.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 17:49:33 by aleveque          #+#    #+#             */
/*   Updated: 2017/03/28 20:01:59 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

t_all	add_to_result(t_all all)
{
	t_list *tmp;

	tmp = all.road;
	ft_lstdel(&all.result);
	while (tmp != NULL)
	{
		ft_lstaddend(&all.result, ft_lstnew(tmp->name, tmp->type));
		tmp = tmp->next;
	}
	return (all);
}

int		more_box(t_all all)
{
	t_list	*tmp;
	t_list	*tmp2;

	all.box_type = 0;
	all.phase = 0;
	tmp = all.road;
	if (tmp != NULL)
	{
		while (tmp != NULL)
		{
			tmp2 = tmp;
			while (tmp2 != NULL)
			{
				tmp2 = tmp2->next;
				all.phase++;
			}
			tmp = tmp->next;
		}
	}
	if (all.result_len == 0 || all.result_len > all.phase)
	{
		all.result_len = all.phase;
		return (1);
	}
	return (0);
}

t_all	compare(t_all all)
{
	t_list *tmp;

	tmp = all.road;
	all.box_type = 0;
	all.phase = 0;
	while (tmp != NULL)
	{
		all.box_type++;
		tmp = tmp->next;
	}
	tmp = all.result;
	while (tmp != NULL)
	{
		all.phase++;
		tmp = tmp->next;
	}
	if (all.box_type > all.phase)
		all = add_to_result(all);
	else if (all.box_type == all.phase && more_box(all) == 1)
		all = add_to_result(all);
	return (all);
}

int		ft_lst_len(t_list *this)
{
	int		len;
	t_list	*tmp;

	len = 0;
	tmp = this;
	while (tmp != NULL)
	{
		tmp = tmp->pipe;
		len++;
	}
	return (len);
}

t_all	find_road(t_all all)
{
	if (all.sol == NULL)
	{
		all.retour = -3;
		return (all);
	}
	all = associate(all);
	all.trash = NULL;
	all = create_soluce(all, small_one(all, NULL).small);
	return (all);
}
