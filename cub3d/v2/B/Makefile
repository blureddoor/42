# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lvintila <lvintila@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 15:02:59 by mvillaes          #+#    #+#              #
#    Updated: 2021/02/01 20:51:22 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=		main.c \
				config_imput.c \
				inti_and_key.c \
				aux.c \
				raycast.c \
				s_tex_res.c \
				./libft/ft_strnstr.c \

NAME	=		cub3D

CFLAGS	=		-Wall -Werror -Wextra -g

MFLAGS	=		-L minilibx -lmlx -framework OpenGL -framework AppKit 

OBJS	=		$(SRCS:.c=.o)


CC		=		gcc $(CFLAGS)

RM		=		rm -f


#libft:
				#make -C libft/
#minilibx:
				#make -C minilibx/
#$(%.o):	$(%.c)
#		$(CC) -o $@ -c $^


$(NAME):		$(OBJS)
				$(MAKE) -C ./libft
				$(CC) $(CFLAGS) $(MFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)
	#gcc -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit main.c -L libft -lft
	#& leaks a.out#

all:			$(NAME)

clean:	
				$(RM) $(OBJS)
				make -C libft/ clean
				make -C minilibx/ clean

fclean:			clean
				$(RM) $(NAME)
				make -C libft/ clean
				make -C minilibx/ clean
				$(RM) $(NAME) $(OBJS)

re:				fclean all

run:	
				./${NAME}

#fclean:
#rm -rf ./a.out

.PHONY:			all clean fclean re libft minilibx
