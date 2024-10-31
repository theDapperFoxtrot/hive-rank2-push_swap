#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>

// information for each value in the unique integer to be sorted
typedef struct s_node
{
	int				value;
	int				current_position;
	bool			upper_half;
	int				final_position;
	int				pre_sorted;
	int				push_price;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_stack
{
	t_node	*first_node;
	t_node	*last_node;
	int		node_count;
}	t_stack;

typedef struct s_data
{
	int		argc;
	char	**argv;
}	t_data;


int	main(int argc, char **argv);
void	malloc_check(t_stack *stack_a, t_stack *stack_b, t_data *data);
t_node *create_node(int value, int position);
void add_node_to_stack(t_stack *stack, t_node *new_node);
void handle_error(t_stack *stack, t_data *data);
void	free_stack(t_stack *stack);
void	error_free_argv(t_data *data);
void	set_default_values(t_stack *stack_a, t_stack *stack_b, char **argv, t_data *data);
int	syntax_error(char *str);
int	is_duplicate(t_stack *stack, long value);
void	init_stack(t_stack *stack, t_data *data);
void    	final_position_finder(t_stack *stack, t_data *data);

#endif