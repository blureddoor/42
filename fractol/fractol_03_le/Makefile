# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvintila <lvintila@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/21 21:33:46 by lvintila          #+#    #+#              #
#    Updated: 2021/08/03 22:08:20 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

YELLOW		=	$(shell tput -Txterm setaf 3)
GREEN		= 	$(shell tput -Txterm setaf 2)
RED			= 	$(shell tput -Txterm setaf 1)

LIBFT		=	libft	

NAME		=	fractol

#BONUS		=	fractol

CC			=	gcc

FLAG		=	-g -Wall -Werror -Wextra -I. -o $(NAME)

MFLAG		=	-lmlx -framework OpenGL -framework Appkit

SANFLAG		=	-fsanitize=address

DIR_S		=	src

DIR_O		=	obj

#DIR_O_BONUS	=	obj_bonus

#DIR_B		=	src_bonus

INC			=	inc

SOURCES_C	=	main.c keys.c fractals_math.c utils.c utils_aux.c\

#SOURCES_B	=	main_bonus.c keys_bonus.c fractal_math_bonus.c \
					utils_bonus.c utils_aux_bonus.c \

SRCS		=	$(addprefix $(DIR_S)/, $(SOURCES_C))

#SRCS_BONUS	=	$(addprefix $(DIR_B)/, $(SOURCES_B))

OBJS		=	$(SRCS:%.c=%.o)

OBJS_BONUS	=	$(SRC_BONUS:%.c=%.o)

all: 			$(NAME)

$(NAME):		$(OBJS)
				@echo "${YELLOW}compiling fract'ol${RESET}"
				@make -C $(LIBFT)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)
				$(CC) $(OBJS) $(FLAG) $(MFLAG) -L $(LIBFT) ./libft/libft.a

$(DIR_O)/%.o:	$(DIR_S)/%.c $(INC)/fractol.h
				@mkdir -p obj
				
bonus:			$(OBJS_BONUS)
				@echo "${RED} compiling with bonus ... ${RESET}"
				@make -C $(LIBFT)
				@ar rc $(BONUS) $(OBJS_BONUS)
				@ranlib $(BONUS)
				$(CC) $(OBJS_BONUS) $(FLAG) $(MFLAG) -L $(LIBFT) ./libft/libft.a

$(DIR_O_BONUS)/%.o:	$(DIR_B)/%.c $(INC)/fractol.h
				mkdir -p obj_bonus


clean:
			make -C $(LIBFT) clean
			rm -f $(OBJS) $(OBJ_BONUS) $(DIR_O) $(DIR_O_BONUS)
			@echo "${GREEN}Cleaned${RESET}"

fclean:		clean
			make -C libft/ fclean
			rm -f $(NAME) $(BONUS)
			@echo "${GREEN}fcleaned ... ${RESET}"

re:			fclean all bonus
	@echo "${GREEN}deleted and recompiled${RESET}"
