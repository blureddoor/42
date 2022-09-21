SRCS		=	dumf.cpp contacts.cpp main.cpp utils.cpp\

OBJS		=	$(SRCS:.cpp=.o)

NAME		=	dumf

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
