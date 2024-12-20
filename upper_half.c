#include "push_swap.h"

void	upper_half_true_false(t_stack *stack)
{
	t_node	*current_node;

	if (!stack->first_node)
		return ;
	current_node = stack->first_node;
	current_node->upper_half = true;
	current_node = current_node->next;
	while (current_node)
	{
		if (current_node->current_position < (stack->node_count / 2) + 1)
			current_node->upper_half = true;
		else
			current_node->upper_half = false;
		current_node = current_node->next;
	}
}

void	is_upper_half(t_stack *stack_a, t_stack *stack_b)
{
	upper_half_true_false(stack_a);
	upper_half_true_false(stack_b);
}
