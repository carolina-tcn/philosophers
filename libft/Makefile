# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctacconi <ctacconi@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 16:04:04 by ctacconi          #+#    #+#              #
#    Updated: 2024/07/18 19:08:20 by ctacconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_putchar.c \
	ft_printf/ft_puthex.c \
	ft_printf/ft_putnbr.c \
	ft_printf/ft_putptr.c \
	ft_printf/ft_putstr.c \
	ft_printf/ft_put_unbr.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

BONUS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c	\
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

HEAD = libft.h ft_printf/ft_printf.h get_next_line/get_next_line.h

OBJ = $(SRC:.c=.o)

BONUS_OBJ=$(BONUS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIB = ar rcs

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $@ $^

%.o: %.c Makefile $(HEAD)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJ) $(BONUS_OBJ)
	$(LIB) $(NAME) $^

.PHONY: all clean fclean re
