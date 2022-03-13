# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 15:14:51 by yoelhaim          #+#    #+#              #
#    Updated: 2022/03/13 20:41:38 by yoelhaim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME='fractol'
HEADER = "fract.h"
CC = cc
FLAG = -Wall -Wextra -Werror -Ofast
SRC= main.c fract-ol.c func.c mouse.c draw.c header.c
OBJ = $(SRC:.c=.o)
AUT=  -lmlx -framework OpenGL -framework AppKit

$(NAME):$(OBJ)
	@$(CC) $(FLAG) $(OBJ) $(AUT) -o $(NAME)
	@echo "succefully compile"

all:$(NAME)

%.o:%.c $(HEADER)
	@$(CC) $(FLAG) -c $< -o $@
clean:
	@rm -rf $(OBJ)
	@echo "succefully remove object files"
fclean: clean
	@rm -rf fractol
	@echo "succefully remove " $(NAME)
re:fclean all
PHONY: clean fclean all re
