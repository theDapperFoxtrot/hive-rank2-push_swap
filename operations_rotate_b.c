#include "push_swap.h"

void	rb(t_stack *stack_b, int print)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (stack_b->node_count < 2)
		return ;
	temp_node = stack_b->first_node;
	temp_node->current_position = stack_b->node_count - 1;
	current_node = stack_b->first_node->next;
	stack_b->first_node = stack_b->first_node->next;
	temp_node->next = NULL;
	current_node->previous = NULL;
	while (current_node)
	{
		current_node->current_position--;
		current_node = current_node->next;
	}
	stack_b->last_node->next = temp_node;
	temp_node->previous = stack_b->last_node;
	stack_b->last_node = temp_node;
	upper_half_true_false(stack_b);
	if (!print)
		ft_putstr_fd("rb\n", 1);
}
