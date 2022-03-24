# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgourlin <jgourlin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 18:36:37 by jgourlin          #+#    #+#              #
#    Updated: 2022/03/24 14:28:06 by jgourlin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# valgrind --leak-check=full --track-fds=yes --trace-children=yes --track-origins=yes --show-leak-kinds=all --suppressions=.ignore_readline -q ./minishell

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
FILES = main.c

FILES_TEST = main_test.c

#    Compilation
NAME = cub3D

TEST= cub3D_test

CC = clang

CFLAGS = -Wall -Wextra -Werror

MLX_FLAG = -Lmlx_linux -Lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm

RM = rm -rf

SRCS = $(addprefix $(SRCS_PATH)/, $(FILES))

SRCS_TEST = $(addprefix $(SRCS_PATH)/, $(FILES_TEST))

OBJS_PATH = objs/

OBJS = $(patsubst $(SRCS_PATH)%.c,    $(OBJS_PATH)%.o, $(SRCS))

OBJS_TEST = $(patsubst $(SRCS_PATH)%.c,    $(OBJS_PATH)%.o, $(SRCS_TEST))

#    Rules
all: $(NAME)

test:$(TEST)

$(NAME): $(LIBFT) $(MLX) $(OBJS_PATH) $(OBJS) $(INC)/$(NAME).h
	@ echo "$(BLUE)\n         ***Make $(NAME) ***\n$(END)"
	$(HIDE) $(CC) $(CFLAGS) $(MLX_FLAG) $(OBJS) -o $(NAME) $(LIBFT) $(MLX)
	@ echo "$(GREEN)\n        ---$(NAME) created ---\n$(END)"

$(TEST): $(LIBFT) $(MLX) $(OBJS_PATH) $(OBJS_TEST) $(INC)/$(NAME).h
	@ echo "$(BLUE)\n         ***Make $(TEST) ***\n$(END)"
	$(HIDE) $(CC) $(CFLAGS) $(MLX_FLAG) $(OBJS_TEST) -o $(TEST) $(LIBFT) $(MLX)
	@ echo "$(GREEN)\n        ---$(TEST) created ---\n$(END)"

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
	$(HIDE) make fclean -C $(LIBFT_DIR)
	$(HIDE) make clean -C $(MLX_PATH)
	@ echo "$(RED)\n        *** Remove $(NAME) ***\n$(END)"

re: fclean all

.PHONY: all clean fclean re test
