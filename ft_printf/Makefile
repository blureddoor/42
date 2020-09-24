NAME		=		libftprintf.a

LIBFT		=		libft

C			=		gcc

FLAGS		=		-Wall -Werror -Wextra

DIR_S		=		srcs

DIR_O		=		obj

HEADER		= 		includes

SOURCES		=		aux.c aux2.c\
					ft_printf.c \
					mods.c converts.c \
					format_char.c format_string.c format_hex.c
					format_pointer.c format_udecimalint.c int.c \
					

OBJS		=		$(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

SRCS		=		$(addprefix $(DIR_S)/,$(SOURCES))

RM			=		@rm -f

all:				${NAME}


$(NAME):	=		${OBJS}

					@make -C $(LIBFT)
					@cp libft/libft.a ./$(NAME)
					@ar rc ${NAME} ${OBJS}
					@ranlib ${NAME}


$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
					@mkdrir -p obj
					@$(CC) $(FLAGS)  -I $(HEADER) -o $@ -c $<
test:				
					@make all misc/main.c

norme:				
					norminette ./libft/
					@echo
					norminette ./$(HEADER)/
					@echo
					norminette ./$(DIR_S)/
				
clean:		
					${RM} ${OBJS}
					make clean -C $(LIBFT)


fclean:				clean
					${RM} ${NAME}
					make fclean -C $(LIBFT)

re:					fclean all

.PHONY:				all re clean fclean
