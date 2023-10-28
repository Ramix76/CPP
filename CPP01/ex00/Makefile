# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framos-p <framos-pn@student.42barcelona.c  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 11:25:37 by framos-p          #+#    #+#              #
#    Updated: 2023/10/28 11:51:28 by framos-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Zombie

SRCS		=	newZombie.cpp \
			main.cpp \
			Zombie.cpp \
			randomChump.cpp

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
	@echo "\nName erased\n"

re: fclean all

.PHONY: all clean fclean re
