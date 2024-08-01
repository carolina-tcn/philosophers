# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctacconi <ctacconi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 18:24:08 by ctacconi          #+#    #+#              #
#    Updated: 2024/08/01 18:20:12 by ctacconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = src/main.c src/check_input.c src/init.c src/threads.c src/philo_actions.c \
		src/monitoring.c

CC = gcc

FLAGS = -Wall -Wextra -Werror -pthread -g

HEAD = inc/philo.h

OBJ = $(SRC:.c=.o)

RM = rm -f

%o: %.c Makefile $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -fsanitize=thread

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re