YELLOW	=	$(shell tput -Txterm setaf 3)
GREEN	= 	$(shell tput -Txterm setaf 2)
RED		= 	$(shell tput -Txterm setaf 1)

NAME	=	fractol

CC		=	gcc

FLAG	=	-Wall -Werror -Wextra -O3

MFLAG	=	-lmlx -framework OpenGL -framework Appkit

SANFLAG	=	-fsanitize=address

SRC		=	 main.c utils.c fractals_math.c utils_aux.c\

INC		=	./inc

SRO		=	$(SRC:.c=.o)

all: 		$(NAME)

$(NAME):	$(SRO)
			make -C ./libft/
			$(CC) $(FLAG) -I$(INC) $(SRC) $(MFLAG) ./libft/libft.a -o $(NAME)

%.o:		%.c ./includes/fractol.h
			$(CC) $(FLAG) -c -o $@ $<
			@echo "${YELLOW}compiling 42 fract'ol${RESET}"


clean:
			make -C libft/ clean
			rm -f $(SRO)
			@echo "${GREEN}Cleaned${RESET}"

fclean:		clean
			make -C libft/ fclean
			rm -rf $(NAME)
			@echo "${GREEN}fcleaned ... ${RESET}"

re:			fclean all
			@echo "${GREEN}deleted and recompiled${RESET}"
