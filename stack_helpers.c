#include "push_swap.h"

void	set_default_values(t_stack *stack_a, t_stack *stack_b, \
	char **argv, t_data *data)
{
	if (data->argc == 2)
	{
		data->argv = ft_split(argv[1], ' ');
		if (data->argv == NULL)
			handle_error(stack_a, stack_b, data);
	}
	else
		data->argv = argv;
	stack_a->first_node = NULL;
	stack_a->last_node = NULL;
	stack_a->node_count = 0;
	stack_b->first_node = NULL;
	stack_b->last_node = NULL;
	stack_b->node_count = 0;
}
