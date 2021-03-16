DIR_S		=	srcs

DIR_O		=	obj

HEADER		=	includes

SOURCES_C	=	lode.c \

SRCS		=	$(addprefix $(DIR_S)/, $(SOURCES_C))

OBJS		=	$(SRCS:%.c=%.o)

NAME		=	cub3D

CC			=	gcc

CFLAGS		=	-g -Wall -Werror -Wextra -I. -o $(NAME)

MFLAGS		=	-lmlx -framework OpenGL -framework AppKit

RM			=	rm -rf

$(NAME):		$(OBJS)
				$(CC) $(OBJS) $(CFLAGS) $(MFLAGS)

$(DIR_O)/%.o:	$(DIR_S)/%.c $(HEADER)/cub.h
				@mkdir -p obj
				@$(CC) $(CFLAGS) -I $(HEADER) -0 $@ -c $<

run:
	./a.out

clean:
	$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

