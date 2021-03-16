YELLOW  	=   $(shell tput -Txterm setaf 3)

GREEN   	=   $(shell tput -Txterm setaf 2)

RED     	=   $(shell tput -Txterm setaf 1)

LIBFT   	=   printf/libft

DIR_S		=	srcs

DIR_SP		=	printf/srcs

DIR_O		=	obj

HEADER		=	includes

DIR_G     	=   gnl

SOURCES_G	=	get_next_line.c get_next_line_utils.c

SOURCES_P	=	aux.c aux_1.c converts.c ft_printf.c mods.c \
				print_char.c print_hex.c print_nbr.c print_pointer.c \
				print_str.c print_u.c \

SOURCES_C	=	aux.c color_bmp.c config_imput.c \
				exit_error.c keys.c main.c map_1.c \
				map_2.c move.c raycast.c \
				res_orientation.c sprite_1.c sprite_2.c \
				texture.c

SRCS	=		$(addprefix $(DIR_S)/,$(SOURCES_C)) \
				$(addprefix $(DIR_SP)/,$(SOURCES_P)) \
				$(addprefix $(DIR_G)/,$(SOURCES_G))

OBJS    =   	$(SRCS:%.c=%.o)

NAME	=   	cub3D


CC      =   	gcc

CFLAGS	=   	-g -Wall -Werror -Wextra -I. -o $(NAME)

MFLAGS	=   	-lmlx -framework OpenGL -framework AppKit -lm

SANFLAG =   	-fsanitize=address

RM		=		rm -rf

all:			libft $(NAME)

$(NAME):		$(OBJS)
				@echo "${YELLOW}compiling cub3D ...${RESET}"
				$(CC) $(OBJS) $(CFLAGS) $(MFLAGS) $(SANFLAG) -L $(LIBFT) $(LIBFT)/libft.a


$(DIR_O)/%.o:	$(DIR_S)/%.c $(HEADER)/cub.h
				@mkdir -p obj
				@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<
				@echo "${YELLOW}Compiling cub3D_2 ...${RESET}"
libft:
				make -C $(LIBFT)

clean:
		make -C $(LIBFT) clean
		$(RM) $(OBJS) $(DIR_O)
		@echo "${GREEN}Cleaned Up, Thank You!!!${RESET}"

fclean:	clean
		$(RM) $(NAME) $(IMG)
		make -C $(LIBFT) fclean
		@echo "${GREEN}Total Fcleaned!!!${RESET}"

re:		fclean all 
		@echo "${GREEN}Deleted and recompiled${RESET}"

run:
		./${NAME} ./maps/easy.cub

.PHONY:			all clean fclean re libft minilibx debug run srcs
