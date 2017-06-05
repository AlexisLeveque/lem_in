/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_road2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:28:41 by aleveque          #+#    #+#             */
/*   Updated: 2017/03/28 20:01:49 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		is_used(t_all all, t_list *list)
{
	t_list *tmp;

	tmp = all.road;
	while (tmp != NULL)
	{
		if (tmp->type == list->type)
			return (0);
		tmp = tmp->next;
	}
	tmp = all.trash;
	while (tmp != NULL)
	{
		if (tmp->type == list->type)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_all	small_one(t_all all, t_list *this)
{
	t_list *tmp;
	t_list *result;

	result = NULL;
	tmp = all.sol;
	all.phase = ft_lst_len(this);
	all.small = NULL;
	while (tmp != NULL)
	{
		if (result == NULL || (ft_lst_len(tmp) <= ft_lst_len(result) &&
					is_used(all, tmp) == 1 && ft_lst_len(tmp) >=
					ft_lst_len(this)))
			result = tmp;
		tmp = tmp->next;
	}
	if (is_used(all, result) == 1 && ft_lst_len(result) >= ft_lst_len(this))
		all.small = result;
	return (all);
}

int		is_possible(t_all all, t_list *is, t_list *tmp, t_list *tmp2)
{
	t_list	*tmp3;
	int		i;

	i = 0;
	tmp = lst_att(all, is->type);
	while (tmp != NULL)
	{
		tmp2 = all.road;
		while (tmp2 != NULL)
		{
			tmp3 = lst_att(all, tmp2->type);
			while (tmp3 != NULL)
			{
				if (ft_strcmp(tmp3->name, tmp->name) == 0 && ft_strcmp(tmp3->
				name, all.strat) != 0 && ft_strcmp(tmp3->name, all.end) != 0)
					i++;
				tmp3 = tmp3->pipe;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->pipe;
	}
	if (i == 0)
		return (1);
	return (0);
}

void	ft_lstdelstart(t_list **list)
{
	t_list *tmp;
	t_list *tmp2;

	tmp2 = *list;
	if (tmp2->next != NULL)
	{
		tmp = tmp2->next;
		ft_lstdelone(&tmp2);
		*list = tmp;
	}
	else
		ft_lstdelone(list);
}

t_all	create_soluce(t_all all, t_list *add)
{
	if (add == NULL)
	{
		all = add_to_result(all);
	}
	else if (is_possible(all, add, NULL, NULL) == 0)
	{
		ft_lstadd(&all.trash, ft_lstnew("0", add->type));
		all = create_soluce(all, small_one(all, add).small);
		ft_lstdelstart(&all.trash);
	}
	else
	{
		ft_lstaddend(&all.road, ft_lstnew("1", add->type));
		all = create_soluce(all, small_one(all, add).small);
		ft_lstdelstart(&all.road);
	}
	return (all);
}
