# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 15:14:51 by yoelhaim          #+#    #+#              #
#    Updated: 2022/03/13 22:21:49 by yoelhaim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME='fractol'
HEADER = "fract.h"
CC = cc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror -Ofast
SRC= main.c fract-ol.c func.c mouse.c draw.c header.c
OBJ = $(SRC:.c=.o)
AUT=  -lmlx -framework OpenGL -framework AppKit

$(NAME):$(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(AUT) -o $(NAME)
	@echo "succefully compile"

all:$(NAME)


%.o:%.c
	@$(CC) $(FLAGS) -c $< -o $@
clean:
	@$(RM) -rf $(OBJ)
	@echo "succefully remove object files"
fclean: clean
	@$(RM) -rf fractol
	@echo "succefully remove " $(NAME)
re:fclean all
PHONY: clean fclean all re
