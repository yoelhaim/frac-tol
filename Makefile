# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 15:14:51 by yoelhaim          #+#    #+#              #
#    Updated: 2022/03/12 12:06:31 by yoelhaim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME='fractol.a'
HEADER = "fract.h"
CC = cc
FLAG = -Wall -Wextra -Werror
SRC= main.c
OBJ = $(SRC:.c=.o)
AUT=  -lmlx -framework OpenGL -framework AppKit

$(NAME):$(OBJ)
	$(CC) $(FLAG) $(OBJ) $(AUT) -o fractol

all:$(NAME)

%.o:%.c HEADER
	$(CC) $(FLAG) -c $< -o $@
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf fractol
re:fclean all
PHONY: clean fclean all re
