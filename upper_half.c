#include "push_swap.h"

void upper_half_true_false(t_stack *stack, t_data *data)
{
	t_node *node_of_interest;

	if (!stack->first_node)
	return ;

	node_of_interest = stack->first_node;
	node_of_interest->upper_half = true;
	node_of_interest = node_of_interest->next;
	while (node_of_interest)
	{
		if (node_of_interest->current_position < ((data->argc - 1) / 2))
			node_of_interest->upper_half = true;
		node_of_interest = node_of_interest->next;
	}
}

void is_upper_half(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	upper_half_true_false(stack_a, data);
	upper_half_true_false(stack_b, data);
}