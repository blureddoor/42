YELLOW  	= 	$(shell tput -Txterm setaf 3)
GREEN		=	$(shell tput -Txterm setaf 2)
RED			=	$(shell tput -Txterm setaf 1)

LIBFT		=	libft

MINILIBX	=	minilibx

DIR_S		=	srcs

DIR_O		=	obj

// DIR_SP		=	printf/srcs

DIR_G		=	gnl

HEADER		=	includes

SOURCES_C	=	main.c move.c texture.c raycast.c utils.c \
				utils_aux.c read_imput.c res.c map_load.c color.c \
				sprite.c sprite_aux.c map_utils.c move_aux.c \

SOURCES_P	=	aux.c aux_1.c converts.c ft_printf.c mods.c \
				print_char.c print_hex.c print_nbr.c print_pointer.c \
				print_str.c print_u.c \

SOURCES_G	=	get_next_line.c get_next_line_utils.c 

SRCS		=	$(addprefix $(DIR_S)/, $(SOURCES_C)) \
				$(addprefix $(DIR_G)/, $(SOURCES_G)) \

OBJS		=	$(SRCS:%.c=%.o)

NAME		=	cub3D

IMG			=	$(NAME).bmp

CC			=	gcc

CFLAGS		=	-g -Wall -Werror -Wextra -I. -o $(NAME)

MFLAGS		=	-lmlx -framework OpenGL -framework AppKit

SANFLAG		=	-fsanitize=adress

RM			=	rm -rf

all:			$(NAME)

$(NAME):		$(OBJS)
				@echo "${YELLOW}... compiling cub3D ...${RESET}"
				@make -C $(LIBFT)
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)
				$(CC) $(OBJS) $(CFLAGS) $(MFLAGS) -L $(LIBFT) $(LIBFT)/libft.a -L $(MINILIBX) $(MINILIBX)/libmlx.a

$(DIR_O)/%.o:	$(DIR_S)/%.c $(HEADER)/cub.h
				@mkdir -p obj
				@echo "${RED}... compiling cub3D---second--- ...${RESET}"

libft:
				make -C $(LIBFT)
run1:
				./cub3D ./maps/easy_1.cub

run2:			
				./cub3D ./maps/map1.cub

runsave:		
				./cub3D ./maps/map1.cub --save

clean:
				make -C $(LIBFT) clean
				$(RM) $(OBJS) $(DIR_O)
				@echo "${GREEN}Cleaned, Thank you!${RESET}"

fclean:			clean
				$(RM) $(NAME) $(IMG)
				make -C $(LIBFT) fclean
				@echo "${GREEN}Total fclean!!!!${RESET}"

re:				fclean all
				@echo "${GREEN}Deleted and recompiled for you !!!${RESET}"

