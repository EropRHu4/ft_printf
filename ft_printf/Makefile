# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: syule <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 16:11:51 by syule             #+#    #+#              #
#    Updated: 2022/01/08 16:12:17 by syule            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

LIST =	ft_putchar.c ft_putstr.c ft_putnbr.c ft_printf.c ft_putnbr_hex.c ft_putnbr_uns.c

OBJ = $(patsubst  %.c,%.o,$(LIST))
OBJ_B = $(patsubst  %.c,%.o,$(LIST_B))

OPTIFLAGS = -O2
FLAGS = -Wall -Wextra -Werror
CC = gcc


all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $?

%.o: %.c
	$(CC) $(FLAGS) $(OPTIFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ) $(OBJ_B)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

bonus: $(BOBJS)
	@make OBJ="$(OBJ_B)" all

.PHONY : all clean fclean re bonus
