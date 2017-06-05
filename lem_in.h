/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:42:20 by aleveque          #+#    #+#             */
/*   Updated: 2017/03/31 14:01:05 by aleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define DIGIT str_is_digit

typedef struct		s_all
{
	int				count;
	int				ant;
	int				ant_end;
	int				nbr_sol;
	int				bol;
	int				retour;
	int				box_type;
	int				phase;
	int				ant_nbr;
	char			*strat;
	char			*end;
	char			**split;
	t_list			*enter;
	t_list			*box;
	t_list			*road;
	t_list			*sol;
	t_list			*start;
	int				result_len;
	t_list			*result;
	t_list			*small;
	t_list			*trash;
}					t_all;

char				*get_name(char *line);
int					str_is_digit(char *str);
void				print_enter(t_all all);
t_all				ft_error_pipes(char *line, t_all all);
t_all				phase1(t_all all, char *line, int i);
t_all				ft_count(t_all all, char *line);
t_all				is_in_list(t_all all, char *name);
void				ft_leaks2(t_all all);
void				ft_leaks(t_all all);
t_all				ft_nbrsol(t_all all);
void				del_end(t_list **start);
t_list				*lst_at_sol(int type, t_all all);
t_all				ft_ant(t_all all);
t_all				initiate(t_all all);
t_all				ft_write(int nbr, char *name, t_all all);
int					ft_error(t_all all);
t_all				add_to_result(t_all all);
t_all				associate(t_all all);
t_list				*lst_att(t_all all, int type);
t_all				create_soluce(t_all all, t_list *list);
t_all				compare(t_all all);
int					ft_lst_len(t_list *thus);
t_all				small_one(t_all all, t_list *thus);
t_all				find_road(t_all all);
t_all				list_road(t_all all);
t_list				*lst_at(t_all all, char *name);

#endif
