# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2.0                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleveque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/16 20:20:16 by aleveque          #+#    #+#              #
#    Updated: 2017/06/05 16:08:44 by aleveque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = lem-in

SRCDIR = src

OBJDIR = obj

SRC = main.c list_road.c find_road.c find_road2.c find_road3.c ft_error.c\
	  ft_ant.c ft_ant2.c del_end_list.c ft_leak.c

OBJ = $(SRC:.c=.o)

OBJP = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

SRCPATH = $(addprefix $(SRCDIR)/, $(SRC))

LIBFT = libft/libft.a

LIBPRINTF = ft_printf/libftprintf.a

all:libcomp  $(OBJDIR) $(NAME)

re: fclean all

libcomp:
	@make -C libft/
	@make -C ft_printf/

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -c -o $@ $^

$(OBJDIR):
	@echo "\033[1;32mcompiling obj"
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJP)
	@echo "\033[1;34mcompiling exec"
	@$(CC) -o $@ $^ $(LIBFT) $(LIBPRINTF)

clean:
	@echo "\033[1;31mcleaning obj"
	@rm -rf $(OBJDIR)
	@make clean -C libft/
	@make clean -C ft_printf/

fclean:
	@echo "\033[1;31mcleaning exec"
	@make fclean -C libft/
	@make fclean -C ft_printf/
	@rm -rf $(OBJDIR)
	@rm -rf $(NAME)
