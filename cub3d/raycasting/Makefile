LIBFT		=	printf/libft

DIR_S		=	srcs

DIR_O		=	obj

DIR_SP		=	printf/srcs

DIR_G		=	gnl

HEADER		=	includes

SOURCES_C	=	 main.c move.c \

SOURCES_P	=	aux.c aux_1.c converts.c ft_printf.c mods.c \
				print_char.c print_hex.c print_nbr.c print_pointer.c \
				print_str.c print_u.c \

SOURCES_G	=	get_next_line.c get_next_line_utils.c 

SRCS		=	$(addprefix $(DIR_S)/, $(SOURCES_C)) \
				$(addprefix $(DIR_SP)/, $(SOURCES_P)) \
				$(addprefix $(DIR_G)/, $(SOURCES_G)) \

OBJS		=	$(SRCS:%.c=%.o)

NAME		=	cub3D

CC			=	gcc

CFLAGS		=	-g -Wall -Werror -Wextra -I. -o $(NAME)

MFLAGS		=	-lmlx -framework OpenGL -framework AppKit

RM			=	rm -rf

all:			libft $(NAME)

$(NAME):		$(OBJS)
				@echo "${YELLOW}... compiling cub3D ...${RESET}"
				$(CC) $(OBJS) $(CFLAGS) $(MFLAGS) -L $(LIBFT) $(LIBFT)/libft.a

$(DIR_O)/%.o:	$(DIR_S)/%.c $(HEADER)/cub.h
				@mkdir -p obj
				@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<
				@echo "${YELLOW}... compiling cub3D---second--- ...${RESET}"

libft:
				make -C $(LIBFT)
run:
	./cub3D

clean:
				make -C $(LIBFT) clean
				$(RM) $(OBJS) $(DIR_O)
				@echo "${GREEN} Cleaned, Thank you! ${RESET}"

fclean:			clean
				$(RM) $(NAME) $(IMG)
				make -C $(LIBFT) fclean
				@echo "${GREEN} Total fclean!!!! ${RESET}"

re:				fclean all
				@echo "${GREEN} Deleted and recompiled for you !!! ${RESET}"

