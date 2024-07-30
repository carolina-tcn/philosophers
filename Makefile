# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: carolinatacconis <carolinatacconis@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 18:24:08 by ctacconi          #+#    #+#              #
#    Updated: 2024/07/30 14:21:22 by carolinatac      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = src/main.c src/check_input.c src/init.c src/threads.c src/philo_actions.c

CC = gcc

FLAGS = -Wall -Wextra -Werror -pthread -g

HEAD = inc/philo.h

OBJ = $(SRC:.c=.o)

RM = rm -f

%o: %.c Makefile $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re