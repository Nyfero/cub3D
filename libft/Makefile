# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsap <gsap@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 14:07:19 by gsap              #+#    #+#              #
#    Updated: 2022/03/09 16:59:42 by gsap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
GREY = \e[90ms
RED = \e[91m
GREEN = \e[92m
YELLOW = \e[93m
BLUE = \e[34m
PURPLE = \e[95m
CYAN = \e[96m
END = \e[39m

#	Showing command
DISP = FALSE

ifeq ($(DISP),TRUE)
	HIDE =
else
	HIDE = @
endif

#	Folders
SRCS_PATH = srcs

#	Files
FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
	ft_memcmp.c ft_calloc.c ft_strlen.c ft_lstrlen.c ft_isalpha.c ft_isdigit.c \
	ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c \
	ft_itoa.c ft_uitoa.c ft_strdup.c ft_strjoin.c ft_strjoin_and_free_s1.c \
	ft_strjoin_and_free_s2.c ft_strjoin_and_free_all.c ft_strtrim.c ft_split.c \
	ft_substr.c ft_strmapi.c ft_free_ls.c get_next_line.c ft_putchar.c ft_putstr.c \
	ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c  ft_putstr_fd_oneline.c

#	Compilation
NAME = libft.a

CC = clang

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -rf

SRCS = $(addprefix $(SRCS_PATH)/,$(FILES))

OBJS_PATH = objs/

OBJS = $(patsubst $(SRCS_PATH)%.c,	$(OBJS_PATH)%.o,	$(SRCS))

INC = inc/libft.h

all: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS)
	$(HIDE) $(AR) $(NAME) $(OBJS)
	@ echo "\n$(CYAN)"
	$(HIDE) ranlib $(NAME)
	@ echo "$(GREEN)\n		--- $(NAME) created ---\n$(END)"

$(OBJS_PATH):
	$(HIDE) mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c $(INC) Makefile
	$(HIDE) $(CC) $(CFLAGS) -I $(INC) -c $< -o $@
	@ echo "$(GREEN)[ OK ]$(END) $(CYAN)${<:.s=.o}$(END)"

clean:
	@ $(RM) $(OBJS_PATH)
	@ echo "$(PURPLE)\n		*** Clean objs in libft ***\n$(END)"

fclean: clean
	@ $(RM) $(NAME)
	@ echo "$(RED)\n		*** Clean $(NAME) ***\n$(END)"

re: fclean all

.PHONY: all clean fclean re
