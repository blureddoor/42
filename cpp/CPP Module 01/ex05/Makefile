SRCS		=	Karen.cpp main.cpp\

OBJS		=	$(SRCS:.cpp=.o)

NAME		=	karen

CXX			=	clang++

CXXFLAGS	=	-Wall -Werror -Wextra -I.

RM			=	rm -f

all			=	$(NAME)

$(NAME):		$(OBJS)
					$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)


fclean:			clean
						$(RM) $(NAME)


re:				fclean $(NAME)

.PHONY:			all clean fclean re