#include "push_swap.h"

void	argc_2(t_stack *stack_a, t_stack *stack_b, char **argv, t_data *data)
{
	data->argv = ft_split(argv[1], ' ');
	stack_a->first_node = NULL;
	stack_a->last_node = NULL;
	stack_a->node_count = 0;
	stack_b->first_node = NULL;
	stack_b->last_node = NULL;
	stack_b->node_count = 0;
}

void	argc_above_2(t_stack *stack_a, t_stack *stack_b, char **argv, t_data *data)
{
		data->argv = argv;
		stack_a->first_node = NULL;
		stack_a->last_node = NULL;
		stack_a->node_count = 0;
		stack_b->first_node = NULL;
		stack_b->last_node = NULL;
		stack_b->node_count = 0;
}
