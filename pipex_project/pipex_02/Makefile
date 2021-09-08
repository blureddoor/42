# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 20:35:15 by lvintila          #+#    #+#              #
#    Updated: 2021/09/08 20:58:37 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW		=	$(shell tput -Txterm setaf 3)
GREEN		=	$(shell tput -Txterm setaf 3)
RED			=	$(shell tput -Txterm setaf 3)

NAME		= 	pipex

CC			=	gcc

FLAG		=	-g -Wall -Werror -Wextra $(NAME)

SANFLAG		=	-fsanitize=adress

DIR_S		=	src

DIR_O		=	obj

INC			=	inc

SOURCES		=	pipex.c \

SRCS		= 	$(addprefix $(DIR_S)/, $(SOURCES))

OBJS		=	$(SRCS:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				@echo "${YELLOW}... compiling pipex... ${RESET}"
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)
				$(CC) $(OBJS) $(FLAG)

$(DIR_O)/%.o:	$(DIR_S)/%.c $(INC)/pipex.h

clean:
				rm -f $(OBJS) $(DIR_O)
				@echo "${GREEN} Cleaned ${RESET}"

fclean:			clean
				rm -f $(NAME)
				@echo "${} fcleaned ... Done!${RESET}"

re:				fclean all
				@echo "${GREEN} ... deleted and recompiled ... Done!${RESET}"
