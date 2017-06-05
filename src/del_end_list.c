/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_end_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:11:21 by aleveque          #+#    #+#             */
/*   Updated: 2017/03/31 14:50:00 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	del_end(t_list **start)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *start;
	tmp2 = *start;
	if (tmp != NULL && start != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		if (tmp2 != tmp)
		{
			while (tmp2->next != tmp)
				tmp2 = tmp2->next;
			tmp2->next = NULL;
		}
		else
			*start = NULL;
		ft_lstdelone(&tmp);
	}
}

t_all	ft_error_pipes(char *line, t_all all)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i] != 0)
	{
		if (line[i] == '-')
			count++;
		i++;
	}
	if (count != 1)
		all.retour = -2;
	return (all);
}

void	print_enter(t_all all)
{
	t_list *tmp;

	tmp = all.enter;
	while (tmp != NULL)
	{
		ft_printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

int		str_is_digit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

char	*get_name(char *line)
{
	int i;
	int x;

	x = 0;
	i = ft_strlen(line) - 1;
	while (x < 2)
	{
		i--;
		if (line[i] == ' ')
			x++;
	}
	return (ft_strsub(line, 0, i));
}
