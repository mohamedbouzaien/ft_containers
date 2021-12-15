# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouzaie <mbouzaie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 21:57:50 by mbouzaie          #+#    #+#              #
#    Updated: 2021/12/15 22:10:09 by mbouzaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers_test

CC = clang++

FLAGS = -g -fsanitize=address -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

HEADER_PATH = incs/

HEADER_INCS = algorithm.hpp functional.hpp iterator.hpp map_tests.hpp map.hpp \
				stack_tests.hpp stack.hpp stl_tree.hpp type_traits.hpp \
				utility.hpp vector_tests.hpp vector.hpp

all		: 	$(NAME)

$(NAME)	:	$(OBJS)
			@$(CC) -o $(NAME) $(FLAGS) $(OBJS)

$(OBJS)	:	$(addprefix $(HEADER_PATH), $(HEADER_INCS))

clean	:	
				@rm -rf $(OBJS)

fclean	:	clean
				@rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re

%.o		:	%.cpp
			@$(CC) $(FLAGS) -o $@ -c $<