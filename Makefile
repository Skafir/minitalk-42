# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skafir <skafir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 21:13:41 by skafir            #+#    #+#              #
#    Updated: 2025/03/06 21:22:54 by skafir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME_CLIENT = client
NAME_SERVER = server
LIBFT = ./libft/libft.a

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

SRC_CLIENT = srcs/client.c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

SRC_SERVER = srcs/server.c srcs/server_utils.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)

NAME_CLIENT_BONUS = client_bonus
BONUS_SRC_CLIENT = bonus/client_bonus.c
BONUS_OBJ_CLIENT = $(BONUS_SRC_CLIENT:.c=.o)

NAME_SERVER_BONUS = server_bonus
BONUS_SRC_SERVER = bonus/server_bonus.c bonus/server_bonus_utils.c
BONUS_OBJ_SERVER = $(BONUS_SRC_SERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(MAKE) --no-print-directory -C ./libft
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(NAME_CLIENT)
	@echo "$(NAME_CLIENT): $(GREEN)Compiled.$(RESET) 👍"
	@echo

$(NAME_SERVER): $(OBJ_SERVER)
	$(MAKE) --no-print-directory -C ./libft
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(NAME_SERVER)
	@echo "$(NAME_SERVER): $(GREEN)Compiled.$(RESET) 👍"
	@echo

$(NAME_CLIENT_BONUS): $(BONUS_OBJ_CLIENT)
	$(MAKE) --no-print-directory -C ./libft
	$(CC) $(CFLAGS) $(BONUS_OBJ_CLIENT) $(LIBFT) -o $(NAME_CLIENT_BONUS)
	@echo "$(NAME_CLIENT_BONUS): $(GREEN)Compiled.$(RESET) 👍"
	@echo

$(NAME_SERVER_BONUS): $(BONUS_OBJ_SERVER)
	$(MAKE) --no-print-directory -C ./libft
	$(CC) $(CFLAGS) $(BONUS_OBJ_SERVER) $(LIBFT) -o $(NAME_SERVER_BONUS)
	@echo "$(NAME_SERVER_BONUS): $(GREEN)Compiled.$(RESET) 👍"
	@echo

bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ_CLIENT) $(OBJ_SERVER)
	rm -rf $(BONUS_OBJ_CLIENT) $(BONUS_OBJ_SERVER)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME_CLIENT) $(NAME_SERVER)
	rm -rf $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)
	@echo "${NAME_CLIENT}, ${NAME_SERVER}, ${NAME_CLIENT_BONUS}, ${NAME_SERVER_BONUS} : ${RED}$ Deleted.${RESET} 👍"
	@echo

re: fclean all