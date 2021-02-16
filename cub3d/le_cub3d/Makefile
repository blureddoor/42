YELLOW  =   $(shell tput -Txterm setaf 3)

GREEN   =   $(shell tput -Txterm setaf 2)

RED     =   $(shell tput -Txterm setaf 1)

LIBFT   =   ./printf/libft

GNL     =   ./gnl/

PRINTF  =   ./printf/srcs/

CUB3D   =   ./srcs/


#SRCS	=	./gnl/get_next_line.c ./gnl/get_next_line.h \
#			./gnl/get_next_line_utils.c \
#			./printf/srcs/aux.c ./printf/srcs/converts.c ./printf/srcs/aux_1.c\
#			./printf/srcs/ft_printf.c ./printf/srcs/mods.c \
#			./printf/srcs/print_char.c ./printf/srcs/print_hex.c \
#			./printf/srcs/print_nbr.c ./printf/srcs/print_pointer.c \
#			./printf/srcs/print_str.c ./printf/srcs/print_u.c \
#			./srcs/aux.c ./srcs/color_bmp.c ./srcs/config_imput.c \
#			./srcs/exit_error.c ./srcs/keys.c ./srcs/main.c ./srcs/map_1.c \
#			./srcs/map_2.c ./srcs/move.c ./srcs/raycast.c \
#			./srcs/res_orientation.c ./srcs/sprite_1.c ./srcs/sprite_2.c \
#			./srcs/texture.c \


OBJS    =   $(SRCS:%.c=%.o)

NAME	=   cub3D

IMG     =   $(NAME).bmp

CC      =   gcc

CFLAGS	=   -g -Wall -Werror -Wextra -I. -o $(NAME)

MFLAGS	=   -lmlx -framework OpenGL -framework AppKit -lm

SANFLAG =   -fsanitize=address

RM		=	rm -rf

all: libft $(NAME)

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

.PHONY:			all clean fclean re libft minilibx debug run
