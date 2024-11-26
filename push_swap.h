#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>

// information for each value in the unique integer to be sorted
typedef struct s_node
{
	long			value;
	int				current_position;
	bool			upper_half;
	long			cost;
	int				dub_rot;
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
}	t_data;


void	malloc_check(t_stack *stack_a, t_stack *stack_b, t_data *data);
t_node	*create_node(long value, int position);
void	add_node_to_stack(t_stack *stack, t_node *new_node);
void	handle_error(t_stack *stack, t_data *data);
void	free_stack(t_stack *stack);
void	free_argv(t_data *data);
void	set_default_values(t_stack *stack_a, t_stack *stack_b, char **argv, t_data *data);
int		syntax_error(char *str);
int		is_duplicate(t_stack *stack, long value);
void	init_stack(t_stack *stack, t_data *data);
void	is_upper_half(t_stack *stack_a, t_stack *stack_b);
void	upper_half_true_false(t_stack *stack);
void	make_moves(t_stack *stack_a, t_stack *stack_b);
void	push_cheapest_to_b(t_stack *a, t_stack *b);
void	push_cheapest_to_a(t_stack *a, t_stack *b);
int		is_sorted(t_stack *stack);
void	determine_costs(t_stack *stack_a, t_stack *stack_b);
t_node	*cheapest_node(t_stack *stack);
void    find_new_min_max(t_stack *stack_a, t_stack *stack_b);
void	target_in_b(t_stack *stack_a, t_stack *stack_b);
void	target_in_a(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack);
void	determine_costs_both(t_stack *outbound_stack, t_stack *inbound_stack, t_node *current_node);
void	determine_costs_ind(t_stack *outbound_stack, t_stack *inbound_stack, t_node *current_node);
int		sim_rotations(t_node *current_node, int current_node_position, int target_node_position, int count);\
// OPERATIONS
void    sa(t_stack *stack_a, int print);
void    sb(t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b);
void    pa(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a, int print);
void	rb(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a, int print);
void	rrb(t_stack *stack_b, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b);


#endif