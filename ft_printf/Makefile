# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcamilo- <rcamilo-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/14 23:43:05 by rcamilo-          #+#    #+#              #
#    Updated: 2020/05/15 00:12:44 by rcamilo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = sources/*.c		\
	   utils/*.c		\

OBJECTS = *.o

LIB = headers/ft_printf.h

all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS) : $(SRCS) $(LIB)
	@gcc -Wextra -Werror -Wall -c -g -I $(LIB) $(SRCS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
