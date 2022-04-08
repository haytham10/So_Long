NAME = so_long

BONUS = so_long_bonus

CC = CC

FLAGS = -Wall -Wextra -Werror

SRCS = ./mandatory/checkers.c ./mandatory/so_long.c \
		./mandatory/control.c ./mandatory/valid_map.c \
		./mandatory/ft_error.c ./mandatory/gameplay.c ./mandatory/init.c \
		./mandatory/loading.c ./mandatory/movement.c ./mandatory/render.c \

SRCS_BONUS = ./bonus/animation_bonus.c ./bonus/checkers_bonus.c \
		./bonus/so_long_bonus.c ./bonus/control_bonus.c \
		./bonus/loading_bonus.c ./bonus/movement_bonus.c \
		./bonus/render_bonus.c ./bonus/valid_map_bonus.c \
		./bonus/ft_error_bonus.c ./bonus/gameplay_bonus.c ./bonus/init_bonus.c \

LIBFT = ./libft/libft.a

MLX_API = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

bonus : $(BONUS)

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) $(MLX_API) -o $(NAME)

$(BONUS) : $(OBJS_BONUS)
	$(CC) $(FLAGS) $(SRCS_BONUS) $(LIBFT) $(MLX_API) -o $(BONUS)

%.o : %.c %.h
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME) $(BONUS)

re : fclean all