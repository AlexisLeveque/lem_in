# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleveque <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/01 16:19:02 by aleveque          #+#    #+#              #
#    Updated: 2017/03/17 15:36:48 by aleveque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCDIR = write

OBJDIR = obj

SRC = writestr.c printf_putstr.c printf_putchar.c printf_putnbr.c\
	   ft_putstr_printf.c printf_puthex.c printf_putoct.c printf_puthexa.c\
	   printf_putpoint.c printf_putwchar.c ft_putwstr.c\
	   ft_putwchar.c ft_itoa_llu.c optn_minus.c optn_nbr.c optn_oct.c\
	   optn_plus.c optn_point.c optn_space.c optn_zero.c ft_conv.c ft_conv2.c\
	   ft_convint.c ft_convint2.c ft_convint3.c ft_printconv.c ft_castperc.c\
	   ft_printf.c wheel_of_destiny.c printf_option.c ft_charwlen.c\
	   ft_atoi.c ft_isdigit.c\
	  ft_strcmp.c\
	  ft_putchar.c\
	  ft_strnstr.c ft_strdup.c\
	  ft_strlen.c\
	  ft_tolower.c ft_toupper.c\
	  ft_nbrlen_base.c ft_itoa_base.c ft_strjoin.c

SRCPATH = $(addprefix $(SRCDIR)/, $(SRC))

OBJP = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

OBJ = $(SRC:.c=.o)

all: $(OBJDIR) $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -c -o $@ $^

$(OBJDIR):
	@echo "\033[1;32mcompiling printf obj"
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJP)
	@echo "\033[1;34mcompiling printf"
	@ar rc $@ $^

clean:
	@echo "\033[1;31mcleaning printf"
	@rm -rf $(OBJDIR)

fclean: clean
	@echo "\033[1;31mcleaning  printf.a"
	@rm -f $(NAME)

re: fclean all
