YELLOW  	=   $(shell tput -Txterm setaf 3)

GREEN   	=   $(shell tput -Txterm setaf 2)

RED     	=   $(shell tput -Txterm setaf 1)

LIBFT   	=   ./printf/libft

DIR_S		=	srcs

DIR_SP		=	./printf/srcs

DIR_O		=	obj

HEADER		=	includes

DIR_G     	=   gnl

PRINTF  	=   ./printf/srcs


SOURCES_G	=	get_next_line.c get_next_line_utils.c \
				
SOURCES_P	=	aux.c converts.c aux_1.c \
				ft_printf.c mods.c \
				print_char.c print_hex.c \
				print_nbr.c print_pointer.c \
				print_str.c print_u.c \
				
SOURCES_C	=	aux.c color_bmp.c config_imput.c \
				exit_error.c keys.c main.c map_1.c \
				map_2.c move.c raycast.c \
				res_orientation.c sprite_1.c sprite_2.c \
				texture.c

SRCS	=		$(addprefix $(DIR_S)/, $(SOURCES_C))
				$(addprefix $(DIR_SP)/, $(SOURCES_P))
				$(addprefix $(DIR_G)/, $(SOURCES_G))


OBJS    =   	$(addprefix $(DOR_O)/, $(SOURCES:.c=.o))

NAME	=   	cub3D

IMG     =   	$(NAME).bmp

CC      =   	gcc

CFLAGS	=   	-g -Wall -Werror -Wextra -I. -o $(NAME)

MFLAGS	=   	-lmlx -framework OpenGL -framework AppKit -lm

SANFLAG =   	-fsanitize=address

RM		=		rm -rf

all:			$(NAME)

$(NAME): $(OBJS)
		@echo "${YELLOW}compiling cub3D ...${RESET}"
		$(CC) $(OBJS) $(CFLAGS) $(MFLAGS)  -L$(LIBFT) $(LIBFT)/libft.a

$(%.o): $(%.c)
		$(CC) -c $^ -o $@ 
		@echo "${YELLOW}Compiling cub3D ...${RESET}"

libft:
		make -C $(LIBFT)

clean:
		make -C $(LIBFT) clean
		$(RM) $(OBJS) 
		@echo "${GREEN}Cleaned!!!${RESET}"

fclean:	clean
		$(RM) $(NAME) $(IMG)
		make -C $(LIBFT) fclean
		@echo "${GREEN}Fcleaned!!!${RESET}"

re:		fclean all 
		@echo "${GREEN}Deleted and recompiled${RESET}"

run:
		./${NAME}

.PHONY:			all clean fclean re libft minilibx debug run srcs
