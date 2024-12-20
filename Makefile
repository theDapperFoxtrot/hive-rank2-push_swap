NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC = main_push_swap.c node_helpers.c free_memory.c stack_helpers.c init_stack.c operations_swap.c operations_push_a.c operations_push_b.c operations_rotate_a.c operations_rotate_b.c operations_rotate_both.c operations_reverse_rotate_a.c operations_reverse_rotate_b.c operations_reverse_rotate_both.c upper_half.c make_moves.c make_moves_utils.c make_moves_utils2.c make_moves_utils3.c find_new_min_max.c
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
