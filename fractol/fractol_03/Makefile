NAME	=	fractol

CC		=	gcc

FLAG	=	-Wall -Werror -Wextra -O3

MFLAG	=	-lmlx -framework OpenGL -framework Appkit

SRC		=	 main.c utils.c fractals_math.c \

INC		=	./inc

SRO		=	$(SRC:.c=.o)

all: 		$(NAME)

$(NAME):	$(SRO)
			make -C ./libft/
			$(CC) $(FLAG) -I$(INC) $(SRC) $(MFLAG) ./libft/libft.a -o $(NAME)

%.o:		%.c ./includes/fractol.h
			$(CC) $(FLAG) -c -o $@ $<

clean:
			make -C libft/ clean
			rm -f $(SRO)

fclean:		clean
			make -C libft/ fclean
			rm -rf $(NAME)

re:			fclean all
