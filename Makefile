# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/30 16:48:59 by ryaoi             #+#    #+#              #
#    Updated: 2017/04/16 23:42:09 by ryaoi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_select

DIR_LIB	= libft

LIBFT	= $(DIR_LIB)/libft.a

SRC		= main.c \
		  exe_cursor.c \
		  handle_signal.c \
		  init_arg.c \
		  init_slc.c \
		  move_cursor.c \
		  task.c \
		  usefull.c \
		  ft_str.c \
		  ft_cursorleft.c \
		  ft_cursorright.c \
		  print_list.c

OBJ		= $(SRC:.c=.o)

INCLUDE	= -Ift_select.h \
		  -I./libft/libft.h

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

.SILENT:

%.o:%.c
	$(CC) $(CFLAGS) -I./$(INCLUDE) -o $@ -c $<

$(LIBFT):
	make -C $(DIR_LIB)
	printf "\033[1m"
	printf "\033[32m"
	printf "[libft.a compiled]\n"
	printf "\033[0m"

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) ./libft/libft.a $(OBJ) $(INCLUDE) -ltermcap
	printf "\033[1m"
	printf "\033[32m"
	printf "[$@ compiled!]\n"
	printf "\033[0m"

clean:
	make clean -C $(DIR_LIB)
	rm -rf $(OBJ)

fclean: clean
	make fclean -C $(DIR_LIB)
	rm -rf $(NAME)

re: fclean all
