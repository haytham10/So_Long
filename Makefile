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

INCLUDE = ./mandatory/so_long.h

INC_BONUS = ./bonus/so_long_bonus.h

MLX_API = -lmlx -framework OpenGL -framework AppKit

GREEN := $(shell tput -Txterm setaf 2)

all : $(NAME)

bonus : $(BONUS)

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJS)
	@echo $(GREEN)"MAKING SO_LONG..."
	@$(CC) $(FLAGS) $(SRCS) $(LIBFT) $(MLX_API) -o $(NAME)

$(BONUS) : $(OBJS_BONUS)
	@echo $(GREEN)"MAKING SO_LONG_BONUS..."
	@$(CC) $(FLAGS) $(SRCS_BONUS) $(LIBFT) $(MLX_API) -o $(BONUS)

%.o : %.c $(INCLUDE) $(INC_BONUS)
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS) $(OBJS_BONUS)
	@echo $(GREEN)"REMOVING .o FILES..."

fclean : clean
	@rm -f $(NAME) $(BONUS)
	@echo $(GREEN)"REMOVING SO_LONG..."

re : fclean all