objects = ft_split.o ft_itoa.o ft_strtrim.o ft_putnbr_fd.o ft_putendl_fd.o ft_putstr_fd.o ft_putchar_fd.o ft_strjoin.o ft_strmapi.o ft_atoi.o ft_strdup.o ft_strlcat.o ft_memmove.o ft_strchr.o ft_substr.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memset.o ft_strlcpy.o ft_strlen.o ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_tolower.o ft_toupper.o
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libft.a

all: $(NAME)

$(NAME): $(objects)
	ar rcs $(NAME) $(objects)

ft_split.o : ft_split.c

ft_itoa.o : ft_itoa.c

ft_putnbr_fd.o : ft_putnbr_fd.c

ft_putendl_fd.o : ft_putendl_fd.c

ft_putstr_fd.o : ft_putstr_fd.c

ft_putchar_fd.o : ft_putchar_fd.c

ft_strmapi.o : ft_strmapi.c

ft_memmove.o : ft_memmove.c

ft_atoi.o: ft_atoi.c

ft_bzero.o: ft_bzero.c

ft_calloc.o: ft_calloc.c

ft_isalnum.o: ft_isalnum.c

ft_isalpha.o: ft_isalpha.c

ft_isascii.o: ft_isascii.c

ft_isdigit.o: ft_isdigit.c

ft_isprint.o: ft_isprint.c

ft_itoa.o: ft_itoa.c

ft_memccpy.o: ft_memccpy.c

ft_memchr.o: ft_memchr.c

ft_memcmp.o: ft_memcmp.c

ft_memcpy.o: ft_memcpy.c

ft_memset.o: ft_memset.c

ft_putchar_fd.o: ft_putchar_fd.c

ft_putendl_fd.o: ft_putendl_fd.c

ft_putnbr_fd.o: ft_putnbr_fd.c

ft_putstr_fd.o: ft_putstr_fd.c

ft_split.o: ft_split.c

ft_strchr.o: ft_strchr.c

ft_strdup.o: ft_strdup.c

ft_strjoin.o: ft_strjoin.c

ft_strlcat.o: ft_strlcat.c

ft_strlcpy.o: ft_strlcpy.c

ft_strlen.o: ft_strlen.c

ft_strmapi.o: ft_strmapi.c

ft_strncmp.o: ft_strncmp.c

ft_strnstr.o: ft_strnstr.c

ft_strrchr.o: ft_strrchr.c

ft_strtrim.o: ft_strtrim.c

ft_substr.o: ft_substr.c

ft_tolower.o: ft_tolower.c

ft_toupper.o: ft_toupper.c

clean:
	rm -f $(objects)
fclean: clean
	rm -f $(NAME)
re: fclean all
