# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framos-p <framos-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 12:20:47 by framos-p          #+#    #+#              #
#    Updated: 2023/11/08 10:52:34 by framos-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	FragTrap

SRCS		=	main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp \
			FragTrap.cpp \

LINK		=	c++
CC		=	c++ -c
DEPFLAGS	=	-MMD -MP
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
RM		=	rm -rf
MAKE	:=	make --no-print-directory
MK		=	Makefile

OBJS		=	${addprefix ${OBJS_DIR}, ${SRCS:.cpp=.o}}
DEPS		=	${addprefix ${OBJS_DIR}, ${SRCS:.cpp=.d}}

OBJS_DIR	=	objs/
SRCS_DIR	=


$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp $(MK)
	@echo "$(BOLD_CYAN)compiling: [$(RED)$<$(BOLD_PURPLE)]"
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) $< -o $@

all:
	@$(MAKE) $(NAME)

$(NAME):: $(OBJS)
	$(LINK) $(CFLAGS) $(INCLUDE) -o $@ $^

$(NAME)::
	@echo "\n$(NAME) compiled\n"

clean:
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(OBJS)
	@$(RM) *.dSYM
	@echo "\nName and objects erased\n"

re: fclean all

.PHONY: all clean fclean re
