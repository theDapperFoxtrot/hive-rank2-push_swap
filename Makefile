NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = main_push_swap.c node_helpers.c free_memory.c stack_helpers.c init_stack.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all
