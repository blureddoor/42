C		= 		gcc

NAME		=		libftprintf.a

FLAGS		=		-Wall -Werror -Wextra

LIBFT		=		libft

DIR_S		=		srcs

DIR_O		=		obj

HEADER		= 		includes

SOURCES		=		aux.c aux2.c \
				ft_printf.c \
				mods.c converts.c \
				write_char.c write_string.c write_hex.c \
				write_pointer.c write_udecint.c write_int.c \

SRCS		=		$(addprefix $(DIR_S)/,$(SOURCES))

OBJS		=		$(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

RM		=		@rm -f

all:				$(NAME)

$(NAME):			$(OBJS)
					@make -C $(LIBFT)
					@cp libft/libft.a ./$(NAME)
					@ar rc $(NAME) $(OBJS)
					@ranlib $(NAME)

$(DIR_O)/%.o:			$(DIR_S)/%.c $(HEADER)/ft_printf.h
					@mkdir -p obj
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
					@rm -f $(OBJS)
					@rm -rf $(DIR_O)
					make clean -C $(LIBFT)


fclean:				clean
					${RM} $(NAME)
					make fclean -C $(LIBFT)

re:					fclean all

.PHONY:				all re clean fclean
