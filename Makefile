# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctacconi <ctacconi@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 18:24:08 by ctacconi          #+#    #+#              #
#    Updated: 2024/07/22 18:54:58 by ctacconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include "philo.h"

NAME = philo

SRC = src/main.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEAD = inc/philo.h

LIBFT = libft/libft.a

OBJ = $(SRC:.c=.o)

DEPS = $(SRC:.c=d)

RM = rm -f

%o: %.c Makefile $(HEAD)
	$(CC) $(FLAGS) -MMD -c $< -o $@

make_libs:
	make -C libft

all: make_libs $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	make clean -C libft
	$(RM) $(OBJ) $(DEPS)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re libs

