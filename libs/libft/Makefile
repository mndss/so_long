NAME = 	libft.a
FLAGS = -Wall -Werror -Wextra 
CC = 	clang
OBJ_SRC =	$(SRC:.c=.o)
SRC =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memccpy.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strlcat.c \
		ft_strlcpy.c\
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \

all: $(NAME)

$(NAME): $(OBJ_SRC)
	ar -rcs $(NAME) $(OBJ_SRC)

$(OBJ_SRC): $(SRC) 
	$(CC) $(FLAGS) -c $(SRC)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ_SRC)

clean:
	$(RM) $(OBJ_SRC)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus so 