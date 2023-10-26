# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 10:44:35 by framos-p          #+#    #+#              #
#    Updated: 2023/09/14 15:01:01 by framos-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	megaphone

SRCS		=	megaphone.cpp

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
