# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/07 09:10:41 by rchavez@stu       #+#    #+#              #
#    Updated: 2024/09/07 09:37:10 by rchavez@stu      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Calculate

SRC = ft_malloc/ft_malloc.c ft_malloc/ft_malloc_bad.c ft_malloc/globals.c\
	ft_malloc/list.c get_next_line/get_next_line.c\
	get_next_line/get_next_line_utils.c main.c extract.c emp_t.c

OBJ = $(SRC:%.c=%.o)

HF = main.h get_next_line/get_next_line.h ft_malloc/ft_malloc.h

CC = cc

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJ) | $(HF)
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean :
	rm -fr $(OBJ)

fclean : clean
	rm -fr $(NAME)

re : fclean all

.PHONY : all clean fclean re