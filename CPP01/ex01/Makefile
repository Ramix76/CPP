# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 12:20:47 by framos-p          #+#    #+#              #
#    Updated: 2023/10/30 14:12:53 by framos-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	zombieHorde

SRCS		=	zombieHorde.cpp \
			main.cpp \
			Zombie.cpp \

CC			=	c++
CFLAGS		=	-g -Wall -Wextra -Werror -std=c++98
RM			=	rm -rf

all:		$(NAME)

$(NAME):	$(SRCS)
	@echo "Compiling $@"
	$(CC) $(CFLAGS) -o $@ $^

clean:

fclean: clean
	@$(RM) $(NAME)
	@$(RM) *.dSYM
	@echo "\nName erased\n"

re: fclean all

.PHONY: all clean fclean re
