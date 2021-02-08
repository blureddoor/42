# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 15:02:59 by mvillaes          #+#    #+#              #
#    Updated: 2020/11/30 18:46:02 by mvillaes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW	:= $(shell tput -Txterm setaf 3)
GREEN	:= $(shell tput -Txterm setaf 2)
RED		:= $(shell tput -Txterm setaf 1)

LIBFT	:= ./printf/libft/
GNL		:= ./GNL/
PRINTF	:= ./printf/
CUB3D	:= ./srcs/
SRCS 	:=	$(wildcard $(GNL)*.c) \
			$(wildcard $(PRINTF)*.c) \
			$(wildcard $(CUB3D)*.c)
OBJS	:= $(SRCS:%.c=%.o)
NAME	:= cub3D
IMG		:= $(NAME).bmp
CC		:= gcc
MLXFLAG	:= -lmlx -framework OpenGL -framework AppKit -lm
CFLAGS	:= -g -Wall -Wextra -Werror -I. -o $(NAME)
SANFLAG := -fsanitize=address

RM		:= rm -rvf

all: libft $(NAME)

$(NAME): $(OBJS)
	@echo "${YELLOW}Compiling cub3D...${RESET}"
	$(CC) $(OBJS) $(CFLAGS) $(MLXFLAG) -L$(LIBFT) $(LIBFT)/libft.a
	

$(%.o): $(%.c)
		$(CC)  -c $^ -o $@
		@echo "${YELLOW}Compiling cub3D...${RESET}"

libft:
	make -C $(LIBFT)

clean:
	make -C $(LIBFT) clean
	$(RM) $(OBJS)
	@echo "${GREEN}Cleaned!!!${RESET}"

fclean: clean
	$(RM) $(NAME) $(IMG)
	make -C $(LIBFT) fclean
	@echo "${GREEN}Fcleaned!!!${RESET}"

re: fclean all
	@echo "${GREEN}Deleted and recompiled${RESET}"

.PHONY: clean fclean all re debug
