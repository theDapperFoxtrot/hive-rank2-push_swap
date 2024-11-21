#include "push_swap.h"

void	rb(t_stack *stack_b, int print)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (stack_b->node_count < 2)
		return ;
	temp_node = stack_b->first_node; // first node is now the last node
	temp_node->current_position = stack_b->node_count - 1; // update the current position
	current_node = stack_b->first_node->next; // second node is now the first node
	stack_b->first_node = stack_b->first_node->next; // first node is now the second node
	temp_node->next = NULL; // first node is now the last node
	current_node->previous = NULL; // second node is now the first node
	while (current_node)
	{
		current_node->current_position--;
		current_node = current_node->next;
	}
	stack_b->last_node->next = temp_node; // last node is now the first node
	temp_node->previous = stack_b->last_node; // last node is now the first node
	stack_b->last_node = temp_node; // last node is now the first node
	upper_half_true_false(stack_b);
	if (!print)
		ft_putstr_fd("rb\n", 1);
}
