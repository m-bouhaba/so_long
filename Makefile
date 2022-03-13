# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouhaba <mbouhaba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 22:19:53 by mbouhaba          #+#    #+#              #
#    Updated: 2022/03/11 22:31:04 by mbouhaba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc
SFLAGS = -Wall -Wextra -Werror
COMP = -lmlx -framework OpenGL -framework AppKit
SRC = so_long.c so_long_utils.c get_next_line.c ft_split.c check.c press.c sides.c ft_putnbr.c check1.c
OBJ = ${SRC:.c=.o}

all : $(NAME)

$(NAME): $(OBJ)
		$(CC) $(SFLAGS) $(SRC) $(COMP) -o $(NAME)

clean :
	rm -rf $(OBJ)
fclean : clean
	 rm -rf $(NAME)
re : fclean all