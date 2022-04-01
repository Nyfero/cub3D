# valgrind --leak-check=full --track-fds=yes --trace-children=yes --track-origins=yes --show-leak-kinds=all

#    Colors
GREY = \e[90m
RED = \e[91m
GREEN = \e[92m
YELLOW = \e[93m
BLUE = \e[34m
PURPLE = \e[95m
CYAN = \e[96m
END = \e[39m

#    Showing command
DISP = FALSE

ifeq ($(DISP),TRUE)
    HIDE =
else
    HIDE = @
endif

#    Includes
INC = inc/

LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a

MLX_PATH = ./minilibx-linux

MLX = $(addprefix $(MLX_PATH)/,libmlx_Linux.a libmlx.a)

#    Folders
SRCS_PATH = srcs

#    Files
FILES = main.c check_args.c parsing.c parsing_texture.c parsing_map.c exit.c \
	print_info.c check_map.c parsing_player.c mini_map.c game.c \
	check_deplacement.c render_3d.c check_horizon.c check_vertical.c \
	calc_utils.c door.c utils_game.c render_3d_utils.c

FILES_BONUS = main_bonus.c check_args.c parsing.c parsing_texture.c parsing_map_bonus.c \
	exit.c print_info.c check_map.c parsing_player.c mini_map.c game.c parsing_map.c \
	check_deplacement.c render_3d.c check_horizon.c check_vertical.c \
	calc_utils.c door.c utils_game.c render_3d_utils.c game_bonus.c exit_bonus.c

#    Compilation
NAME = cub3D

BONUS = cub3D_bonus

CC = clang

CFLAGS = -Wall -Wextra -Werror

MLX_FLAG = -Lmlx_linux -Lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm

RM = rm -rf

SRCS = $(addprefix $(SRCS_PATH)/, $(FILES))

SRCS_BONUS = $(addprefix $(SRCS_PATH)/, $(FILES_BONUS))

OBJS_PATH = objs/

OBJS = $(patsubst $(SRCS_PATH)%.c,    $(OBJS_PATH)%.o, $(SRCS))

OBJS_BONUS = $(patsubst $(SRCS_PATH)%.c,    $(OBJS_PATH)%.o, $(SRCS_BONUS))

#    Rules
all: $(NAME)

bonus:$(BONUS)

$(NAME): $(LIBFT) $(MLX) $(OBJS_PATH) $(OBJS) $(INC)/$(NAME).h
	@ echo "$(BLUE)\n         ***Make $(NAME) ***\n$(END)"
	$(HIDE) $(CC) $(CFLAGS) $(MLX_FLAG) $(OBJS) -o $(NAME) $(LIBFT) $(MLX)
	@ echo "$(GREEN)\n        ---$(NAME) created ---\n$(END)"

$(BONUS): $(LIBFT) $(MLX) $(OBJS_PATH) $(OBJS_BONUS) $(INC)/$(NAME).h
	@ echo "$(BLUE)\n         ***Make $(BONUS) ***\n$(END)"
	$(HIDE) $(CC) $(CFLAGS) $(MLX_FLAG) $(OBJS_BONUS) -o $(BONUS) $(LIBFT) $(MLX)
	@ echo "$(GREEN)\n        ---$(BONUS) created ---\n$(END)"

$(LIBFT): libft/Makefile
	@ echo "$(BLUE)\n        ***Make Libft ***\n$(END)"
	$(HIDE) make -C $(LIBFT_DIR)

$(MLX):
	@ echo "$(BLUE)\n		***Make MinilibX ***\n$(END)"
	$(HIDE) make -C $(MLX_PATH)
	@ echo "$(GREEN)\n        ---MinilibX created ---\n$(END)"

$(OBJS_PATH):
	$(HIDE) mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC)/$(NAME).h Makefile
	$(HIDE) $(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	@ echo "$(GREEN)[ OK ]$(END) $(CYAN)${<:.s=.o}$(END)"

clean:
	$(HIDE) $(RM) $(OBJS_PATH)
	$(HIDE) make clean -C $(LIBFT_DIR)
	@ echo "$(PURPLE)\n        ***Clean objects ***\n$(END)"

fclean: clean
	$(HIDE) $(RM) $(NAME)
	$(HIDE) $(RM) $(BONUS)
	$(HIDE) make fclean -C $(LIBFT_DIR)
	$(HIDE) make clean -C $(MLX_PATH)
	@ echo "$(RED)\n        *** Remove $(NAME) ***\n$(END)"

re: fclean all

.PHONY: all clean fclean re bonus
