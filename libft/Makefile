# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmokhtar <hmokhtar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 23:33:37 by hmokhtar          #+#    #+#              #
#    Updated: 2022/03/31 14:12:42 by hmokhtar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_putchar.c ft_putstr.c ft_strjoin.c ft_strlen.c ft_realloc.c ft_putnbr.c \
		ft_memcpy.c ft_strchr.c gnl.c ft_memcpy.c  ft_memmove.c ft_itoa.c ft_split.c\

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
