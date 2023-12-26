NAME = push_swap

LIBFT = libft.a

PRINTF = libftprintf.a

SRC_FILE = push_swap.c t_list.c check_for_error.c

CFLAGS = -Wall -Wextra -Werror

OBJ = ${SRC_FILE:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a .
	make -C printf
	cp printf/libftprintf.a .
	gcc $(CFLAGS) $(OBJ) -I include $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	make clean -C libft
	make clean -C printf
	rm $(OBJ)

fclean: clean
	make fclean -C libft
	make fclean -C printf
	rm $(NAME)

re : fclean all
