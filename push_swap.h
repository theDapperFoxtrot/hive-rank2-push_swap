#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>

// information for each value in the unique integer to be sorted
typedef struct s_node
{
	int				value;
	int				current_position;
	bool			upper_half;
	int				final_position;
	int				pre_sorted;
	int				cost;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_stack
{
	t_node	*first_node;
	t_node	*last_node;
	t_node	*max;
	t_node	*min;
	t_node	*cheapest;
	int		node_count;
}	t_stack;

typedef struct s_data
{
	int		argc;
	char	**argv;
	int		*sorted_array;
}	t_data;


void	malloc_check(t_stack *stack_a, t_stack *stack_b, t_data *data);
t_node	*create_node(int value, int position);
void	add_node_to_stack(t_stack *stack, t_node *new_node);
void	handle_error(t_stack *stack, t_data *data);
void	free_stack(t_stack *stack);
void	error_free_argv(t_data *data);
void	set_default_values(t_stack *stack_a, t_stack *stack_b, char **argv, t_data *data);
int		syntax_error(char *str);
int		is_duplicate(t_stack *stack, long value);
void	init_stack(t_stack *stack, t_data *data);
void	sorting(t_stack *stack_a, t_stack *stack_b, t_data *data);
void	is_upper_half(t_stack *stack_a, t_stack *stack_b, t_data *data);
void	upper_half_true_false(t_stack *stack, t_data *data);
void	make_moves(t_stack *stack_a, t_stack *stack_b, t_data *data);
void	push_cheapest_to_b(t_stack *a, t_stack *b, t_data *data);
void	push_cheapest_to_a(t_stack *a, t_stack *b, t_data *data);
int		is_sorted(t_stack *stack);
void	determine_costs(t_stack *stack);
t_node	*cheapest_node(t_stack *stack);
// OPERATIONS
void    sa(t_stack *stack_a, int print, t_data *data);
void    sb(t_stack *stack_b, int print, t_data *data);
void	ss(t_stack *stack_a, t_stack *stack_b, t_data *data);
void    pa(t_stack *stack_a, t_stack *stack_b, t_data *data);
void    pb(t_stack *stack_a, t_stack *stack_b, t_data *data);
void	ra(t_stack *stack_a, int print, t_data *data);
void	rb(t_stack *stack_b, int print, t_data *data);
void	rr(t_stack *stack_a, t_stack *stack_b, t_data *data);
void	rra(t_stack *stack_a, int print, t_data *data);
void	rrb(t_stack *stack_b, int print, t_data *data);
void	rrr(t_stack *stack_a, t_stack *stack_b, t_data *data);


#endif