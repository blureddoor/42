C			=	gcc

NAME		=	libftprintf.a

FLAGS		=	-Wall -Werror -Wextra

LIBFT		=	libft

DIR_S		= 	srcs

DIR_O		=	obj

HEADER		=	includes

SOURCES		=	

SRCS		=	$(addprefix $(DIR_S)/ ,$(SOURCES))

OBJS		=	$(addprefix $(DIR_S)/, $(SRCS:.c=.o))

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

RM			=	rm -f

$(NAME):	${OBJS}
				@make -C $(LIBFT)
				@cp libft/libft.a ./$(NAME)
				@ar rc ${NAME} ${OBJS}
				@ranlib ${NAME}

$(DIR_O)/%.o:	$(SRCS)/%.c $(HEADER)/ft_printf.h
				@mkdir -p obj
				@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

all:		${NAME}

clean:
			${RM} ${OBJS}
			@rm -rf $(DIR_O)
			@make clean -C $(LIBFT)
fclean:		clean
			${RM} ${NAME}
			@make fclean -C $(LIBFT)

re:			fclean bonus

.PHONY:		bonus all clean fclean re
