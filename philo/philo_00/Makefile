YELLOW		=	$(shell tput -Txterm setaf 3)
GREEN		=	$(shell tput -Txterm setaf 3)
RED			=	$(shell tput -Txterm setaf 3)

NAME		=	philo

CC			=	gcc

FLAG		=	-Wall -Wextra -Werror -lpthread -o $(NAME)

DIR_S		=	src

DIR_O		=	obj

INC			= 	inc

SOURCES		=	philo.c utils.c init.c utils_aux.c \
				threads.c philo.c main.c \

SRCS		=	$(addprefix $(DIR_S)/, $(SOURCES))

OBJS		=	$(SRCS:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				@echo "${YELLOW}... compiling philo ...${RESET}"
				@ar rc $(NAME) $(OBJS)
				@ranlib $(NAME)
				$(CC) $(OBJS) $(FLAG)

$(DIR_O)/%.o:	$(DIR_S)/%.c $(INC)/philo.h

clean:			
				rm -f $(OBJS) $(DIR_O)
				@echo "${GREEN} Cleaned ${RESET}"

fclean:			clean
				rm -f $(NAME)
				@echo "${GREEN} fcleaned ... ${RESET}"

re:				fclean all
				@echo "${RED} deleted and recompiled ... ${RESET}"
