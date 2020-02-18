SRCS		=	ft_memset.c ft_strlen.c ft_atoi.c \
			ft_strchr.c ft_substr.c ft_strjoin.c ft_strcpy.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_substr.c
SRCS_BONUS	=	ft_lstadd_front.c ft_lstsize.c ft_lstnew.c \
				ft_lstdelone.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS		=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.0}
NAME		=	libft.a
CC			=	cc
RM			=	rm -f
CFLAGS		= 	-Wall -Werror -Wextra
.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
				ar rc	${NAME} ${OBJS}
				ranlib	${NAME}

all:		${NAME}
clean:
		 		${RM} ${OBJS}
fclean:		clean
				${RM} ${NAME}

re:				fclean all
