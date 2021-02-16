YELLOW  =   $(shell tput -Txterm setaf 3)

GREEN   =   $(shell tput -Txterm setaf 2)

RED     =   $(shell tput -Txterm setaf 1)

LIBFT   =   ./printf/libft

GNL     =   ./gnl/

PRINTF  =   ./printf/srcs/

CUB3D   =   ./srcs/

SRCS	=	$(wildcard $(GNL)*.c) \
			$(wildcard $(PRINTF)*.c ) \
			$(wildcard $(CUB3D)*.c)

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
