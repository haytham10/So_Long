# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 23:33:37 by hmokhtar          #+#    #+#              #
#    Updated: 2022/03/18 23:40:28 by hmokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_putchar.c ft_putstr.c ft_strlen.c get_next_line_utils.c get_next_line.c ft_realloc.c

NAME = libft.a

OBJS = $(SRCS:.c=.o)

CC =gcc

FLAGS =-Wall -Wextra -Werror

all : $(NAME)

%.o : %.c libft.h
	@$(CC) $(FLAGS) -c $<

$(NAME):$(OBJS)
	@$(CC) $(FLAGS) -c $(SRCS)
	@ar cr $@ $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
