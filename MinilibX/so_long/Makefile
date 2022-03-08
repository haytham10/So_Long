# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 23:39:12 by hmokhtar          #+#    #+#              #
#    Updated: 2022/03/06 00:33:42 by hmokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c data_init.c game_init.c map_init.c map_read.c 
		\ map_parsing.c map_isvalid.c map_height.c map_width.c 
		\ destroyer.c death.c events.c movement.c update.c 
		\ draw.c draw_utils.c 

OBJS = $(SRCS:.c=.o)

NAME = so_long

CC = cc

FLAGS = -Wall -Wextra -Werror

GREEN := $(shell tput -Txterm setaf 2)

all : $(NAME)

%.o : %.c %.h
	@$(CC) $(FLAGS) -c $<

$(NAME):$(OBJS)
	@$(CC) $(FLAGS) -c $(SRCS) $(OBJS) -o $(NAME)
	@echo $(GREEN)"DONE MAKING SO_LONG"
	
clean:
	@rm -f $(OBJS)

fclean: clean
		@rm -f $(CLIENT) $(SERVER)

re: fclean all
norm :
	@norminette *.c *.h