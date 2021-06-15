#makefile fractol
YELLOW		=	$(shell tput -Txterm setaf 3)
GREEN		=	$(shell tput -Txterm setaf 2)
REDI		=	$(shell tput -Txterm setaf 1)

LIBFT		=	libft

MINILIBX	=	minilibx

DIR_S		=	src

DIR_O		=	obj

DIR_G		=	gnl

HEADER		=	includes

SOURCES_C	=	main.c

SRC			=	$(addprefix $(DIR_S)/, $(SOURES_C)) \
				$(addprefix $(DIR_G)/, $(SOURCES_G)) \

OBJS		=	$(SRC:%.c=%.o)

NAME		=	fractol

CC			=	gcc

CFLAGS		=	-g -Wall -Werror -Wextra -I. -o $(NAME)

MFLAGS		=	-lmlx -framework OpenGL -framework AppKit

SANFLAG		=	-fsanitize=adress

RM			=	rm -rf

all:			$(NAME)

$(NAME):		$(OBJS)
				@echo "${YELLOW} ... compiling fractol ... ${RESET}"
				@make -C $(LIBFT)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)
				$(CC) $(OBJS) $(CFLAGS) $(MFLAGS) -L $(LIBFT) $(LIBFT)/libft.a

$(DIR_O)/%.o:	$(DIR_S)/%.c $(HEADER)/fractol.h
				@mkdir -p obj
				@echo "${RED} ... compiling fractol second ... ${RESET}"

libft:
				make -C $(IBFT)

clean:
				make -C $(LIBFT) clean
				$(RM) $(OBJS) $(DIR_O)
				@echo "${GREEN}fractol Cleaned!!! ...${RESET}"

fclean:			clean
				$(RM) $(NAME)
				make -C $(LIBFT) fclean
				@echo "${GREEN}Total fcleaned fractol ...${RESET}"

re:				fclean all
				@echo "${GREEN} Deleted, cleaned and recompiled fractol${RESET}"
