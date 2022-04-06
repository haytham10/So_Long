# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 12:23:35 by hmokhtar          #+#    #+#              #
#    Updated: 2022/04/06 12:40:47 by hmokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c animation.c errooor.c get_map.c img_init.c \
		map_check.c movement.c utils.c \

CC = cc

FLAGS = -Wall -Werror -Wextra

LIBFT = ./libft/libft.a

MLX = ./mlx/libmlx.a

MLX_API = -Lmlx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

OBJS = $(SRC:.c=.o)

$(NAME) : $(OBJS)
	@$(CC) $(OBJ) $(MLX) $(LIBFT) $(MLX_API) -o $(NAME)

%.o : %c
	@$(CC) $(FLAGS) -Imlx -c $< -o $@

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all