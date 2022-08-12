NAME = libft.a

CFILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
				ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_striteri.c ft_strtrim.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_printf.c ft_putchar.c ft_putnbr_un.c ft_putnbr.c ft_putp.c ft_putstr.c ft_putx.c ft_type.c 

OFILES = $(CFILES:%.c=%.o)

all: $(NAME)

$(NAME) : $(OFILES)
	ar -rcs ${NAME} ${OFILES}

%.o : %.c libft.h
	gcc -Wall -Wextra -Werror -c $<

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
