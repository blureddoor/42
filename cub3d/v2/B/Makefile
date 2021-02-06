# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 15:02:59 by lvintila          #+#    #+#              #
#    Updated: 2021/02/01 20:51:22 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW  =       $(shell tput -Txterm setaf 3)

GREEN   =       $(shell tput -Txterm setaf 2)

RED     =       $(shell tput -Txterm setaf 1)

LIBFT   =       ./libft/

GNL     =       ./gnl/

PRINTF  =       ./printf/

CUB3D   =       srcs/

SRCS	=		$(wildcard $(GNL)*.c) \
                $(wildcard $(PRINTF)*.c) \
                $(wildcard $(CUB3D)*.c) \

OBJS    =       $(SRCS:%.c=%.o)

NAME	=		cub3D

IMG     =       $(NAME).bmp

CC      =       gcc

CFLAGS	=		-g -Wall -Werror -Wextra -I. -o $(NAME)

MFLAGS	=		-lmlx -framework OpenGL -framework AppKit -lm

SANFLAG =       -fsanitize=address

RM		=		rm -rf

all:    libft $(NAME)

$(NAME): $(OBJS) @echo "${YELLOW}compiling cub3D ...${RESET}" $(CC) $(CFLAGS) $(MFLAGS) $(OBJS) -L$(LIBFT) $(LIBFT)/libft.a

$(%.o): $(%.c)
        $(CC) -c $^ -o $@
        @echo "${YELLOW}Compiling cub3D ...${RESET}"

libft: make -C $(LIBFT)

clean:	
				$(RM) $(OBJS)
				make -C $(LIBFT) clean
				make -C minilibx/ clean
                @echo "${GREEN}Cleaned!!!${RESET}"

fclean:			clean
				$(RM) $(NAME) $(IMG)
				make -C libft/ fclean
				make -C minilibx/ fclean
				$(RM) $(NAME) $(OBJS)
                @echo "${GREEN}Fcleaned!!!${RESET}"

re:				fclean all
                @echo "${GREEN}Deleted and recompiled${RESET}"

run:	
				./${NAME}

.PHONY:			all clean fclean re libft minilibx debug run
