# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpraca-a <kpraca-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/01 18:40:52 by kpraca-a          #+#    #+#              #
#    Updated: 2020/05/02 18:09:56 by kpraca-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Werror -Wextra

HEADER = libftprintf.h	\
	libft.h		\

NAME =  libftprintf.a

LIBFT = ./Libft

SRC =	ft_printf.c		\
	ft_strlen.c		\
	ft_writechar.c		\
	ft_writenbr.c		\
	ft_writestr.c		\
	ft_itoa.c		\
	ft_bzero.c		\
	ft_writemalloc.c	\
	ft_atoi.c		\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created!"
	@ranlib $(NAME)
	@echo "$(NAME) created!"

%.o: %.c
	@gcc $(FLAG) -I includes -c $< -o $@


clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re
