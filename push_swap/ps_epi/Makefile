##
## Makefile for pushswap in /home/boulay_b/Rendu/CPE_2014_Pushswap
##
## Made by arnaud boulay
## Login   <boulay_b@epitech.net>
##
## Started on  Mon Dec  8 17:34:57 2014 arnaud boulay
## Last update Sat Dec 13 19:29:13 2014 arnaud boulay
##

NAME	= push_swap

SRCSFO	= sources/

SRCS	= $(SRCSFO)main.c \
	  $(SRCSFO)list.c \
	  $(SRCSFO)op.c \
	  $(SRCSFO)sorting.c \
	  $(SRCSFO)tools.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Iinclude -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	cc -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
