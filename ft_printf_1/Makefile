C			=	gcc

NAME		=	libftprintf.a

FLAGS		=	-Wall -Werror -Wextra

LIBFT		=	libft

DIR_S		= 	srcs

DIR_O		=	obj

HEADER		=	includes

SOURCES		=	aux.c converts.c ft_printf.c mods.c parse.c \
				print_hex.c print_char.c print_nbr.c print_pointer.c \
				print_str print_u.c print_uhex.c \

SRCS		=	$(addprefix $(DIR_S)/,$(SOURCES))

OBJS		=	$(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all:			$(NAME)

$(NAME):	$(OBJS)
				@make -C $(LIBFT)
				@cp libft/libft.a ./$(NAME)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)

$(DIR_O)/%.o:	$(DIR_S)/%.c $(HEADER)/ft_printf.h
				@mkdir -p obj
				@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<


clean:
			@rm -f $(OBJS)
			@rm -rf $(DIR_O)
			@make clean -C $(LIBFT)
fclean:		clean
			@rm -f $(NAME)
			@make fclean -C $(LIBFT)

re:			fclean all

.PHONY:		all clean fclean re
