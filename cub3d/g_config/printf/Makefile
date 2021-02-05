# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/03 19:10:04 by mvillaes          #+#    #+#              #
#    Updated: 2020/08/19 19:18:47 by mvillaes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

objects = ft_itoatuning.o ft_char.o ft_flags.o ft_hex.o ft_int.o ft_parser.o ft_percent.o ft_pointer.o ft_printf.o ft_string.o ft_strtolower.o ft_uint.o ft_utl.o ft_width.o ft_putchar.o ft_putsp.o
libft_objects = ./libft/*.o
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(objects) $(libft_objects)
	ar rcs $(NAME) $(objects) $(libft_objects)
$(libft_objects):
	make -C libft/ 
$(objects): $(objects:.o=.c)
	$(CC) $(CFLAGS) $(objects:.o=.c)
clean:
	rm -f $(objects) $(libft_objects)
fclean: clean
	rm -f $(NAME) ./libft/libft.a
re: fclean all