# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmieshko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/08 12:51:55 by kmieshko          #+#    #+#              #
#    Updated: 2018/06/08 12:51:57 by kmieshko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

INCL = ./incl/fractol.h

SRCS = ./srcs/ft_create_frct.c \
		./srcs/ft_manage.c \
		./srcs/ft_get_color.c \
		./srcs/ft_pixel_put.c \
		./srcs/ft_print_rext.c \
		./srcs/ft_kind_of_fractals.c \
		./srcs/ft_mouse.c \
		./srcs/ft_factor_expose.c \
		./srcs/main.c \
		./srcs/ft_pthread.c

OBJ = $(SRCS:.c=.o)

LIB = libft/libft.a

COMPILE = gcc -c

FLAGS = -Wall -Wextra -Werror

FLAGS_FR = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(OBJ) $(FLAGS) $(FLAGS_FR) $(LIB) -o $(NAME)

%.o: %.c
	$(COMPILE) -o $@ $< $(FLAGS) 
	
clean:
	make clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all
	make re -C ./libft