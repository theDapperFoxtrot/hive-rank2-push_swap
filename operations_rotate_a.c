#include "push_swap.h"

void	rotate_a(t_stack *stack_a)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (stack_a->node_count < 2)
		return ;
	temp_node = stack_a->last_node;
	temp_node->current_position = 0;
	temp_node->next = stack_a->first_node->next;
	temp_node->previous = NULL;

	stack_a->last_node = stack_a->first_node;
	stack_a->last_node->next = NULL;
	stack_a->last_node->previous = ;
	current_node = stack_a->first_node;
	while (current_node)
	{
		stack_a->first_node = stack_a->first_node;
		current_node = current_node->next;
	}
	stack_a->first_node = temp_node;
}
