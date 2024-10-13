#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>

// information for each value in the unique integer to be sorted
typedef struct s_stack_node
{
	int					value;
	int					current_position;
	bool				upper_half;
	int					final_position;
	int					push_price;
	struct s_stack_node	*next_biggest_node;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
}	t_stack_node;

#endif