# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvillaes <mvillaes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 15:02:59 by mvillaes          #+#    #+#              #
#    Updated: 2021/01/28 20:40:52 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit main.c ejemplo.cub  && ./a.out
	#& leaks a.out#

fclean:
	rm -rf ./a.out
