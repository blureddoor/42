# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvintila <lvintila@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/08 20:35:15 by lvintila          #+#    #+#              #
#    Updated: 2021/09/27 21:55:37 by lvintila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW		=	$(shell tput -Txterm setaf 3)
GREEN		=	$(shell tput -Txterm setaf 3)
RED			=	$(shell tput -Txterm setaf 3)

#LIBFT		=	libft

NAME		= 	pipex

#NAME_FILE_2	=	outfile

CC			=	gcc

FLAG		=	-g -Wall -Werror -Wextra -I. -o $(NAME)

SANFLAG		=	-fsanitize=address

DIR_S		=	src

DIR_O		=	obj

INC			=	inc

SOURCES		=	pipex.c utils.c ft_isspace.c ft_putstr_fd.c \
				ft_split.c ft_strjoin.c ft_strlen.c ft_strncmp.c \
				ft_substr.c ft_strchr.c \

SRCS		= 	$(addprefix $(DIR_S)/, $(SOURCES))

OBJS		=	$(SRCS:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				@echo "${YELLOW}... compiling pipex... ${RESET}"
#				@make -C $(LIBFT)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)
				$(CC) $(OBJS) $(FLAG)
#				$(CC) $(OBJS) $(FLAG) -L $(LIBFT) ./libft/libft.a

$(DIR_O)/%.o:	$(DIR_S)/%.c $(INC)/pipex.h

clean:
#				make -C $(LIBFT) clean
				rm -f $(OBJS) $(DIR_O)
				@echo "${GREEN} Cleaned ${RESET}"

fclean:			clean
#				make -C libft/ fclean
				rm -f $(NAME)
				@echo "${GREEN} fcleaned ... Done!${RESET}"

re:				fclean all
				@echo "${GREEN} ... deleted and recompiled ... Done!${RESET}"
