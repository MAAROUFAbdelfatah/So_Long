NAME := so_long

CFILES :=  so_long.c

OFILES := $(CFILES:%.c=%.o)

LIBFT := libft/libft.a

PATH_H := libft/

HEADER := so_long.h

GCC_FLAGS := -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OFILES)
	$(MAKE) -C $(PATH_H)
	gcc $(GCC_FLAGS) $^ -o $(NAME) $(LIBFT)

%.o : %.c $(HEADER)
	gcc $(GCC_FLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(PATH_H) clean
	rm -f $(OFILES)

fclean: clean
	$(MAKE) -C $(PATH_H) fclean
	rm -f $(NAME)

re: fclean all