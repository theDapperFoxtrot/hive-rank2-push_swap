#include "push_swap.h"

void	target_in_b(t_stack *stack_a, t_stack *stack_b)
{
	long	closest_smaller;
	t_node	*target;
	t_node	*current_node_b;

	while (stack_a)
	{
		closest_smaller = LONG_MIN;
		current_node_b = stack_b->first_node;
		while (current_node_b)
		{
			if (current_node_b->value < stack_a->first_node->value && current_node_b->value > closest_smaller)
			{
				closest_smaller = current_node_b->value;
				target = current_node_b;
			}
			current_node_b = current_node_b->next;
		}
		if (closest_smaller == LONG_MIN)
			stack_a->first_node->target = max_elem(stack_b);
		else
			stack_a->target = target;
		stack_a = stack_a->next;
	}
}
