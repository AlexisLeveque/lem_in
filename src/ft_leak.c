/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leak.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:33:00 by aleveque          #+#    #+#             */
/*   Updated: 2017/03/31 15:04:06 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	ft_leaks2(t_all all)
{
	ft_lstdel(&all.enter);
	ft_lstdel(&all.box);
}

void	ft_leaks(t_all all)
{
	t_list *tmp;

	tmp = all.box;
	while (tmp != NULL)
	{
		ft_lstdel(&tmp->pipe);
		tmp = tmp->next;
	}
	ft_lstdel(&all.box);
	ft_lstdel(&all.road);
	ft_lstdel(&all.sol);
	ft_lstdel(&all.result);
	ft_lstdel(&all.small);
	ft_lstdel(&all.trash);
	ft_lstdel(&all.enter);
	free(all.strat);
	free(all.end);
}
