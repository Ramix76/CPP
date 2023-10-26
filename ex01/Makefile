# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 12:05:33 by framos-p          #+#    #+#              #
#    Updated: 2023/10/26 15:10:22 by framos-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	phonebook

SRCS		=	phonebook.cpp main.cpp contact.cpp

OBJS		=	$(SRCS:%.cpp=%.o)

CC			=	c++
CFLAGS		=	-g -Wall -Werror -Wextra -std=c++98
RM			=	rm -rf

all: $(NAME)

$(NAME): $(SRCS)
	@echo "Linking $@"
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(RM) $(OBJS)
	@echo "\n Objects files deleted\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "\nName erased\n"

re: fclean all

.PHONY: all clean fclean re
