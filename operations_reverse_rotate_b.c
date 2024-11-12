#include "push_swap.h"

void	reverse_rotate_b(t_stack *stack_b, int print, t_data *data)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (stack_b->node_count < 2)
		return ;
	temp_node = stack_b->last_node; // last node is now the first node
	temp_node->current_position = 0; // update the current position
	current_node = stack_b->last_node->previous; // first node is now the last node
	stack_b->last_node = stack_b->last_node->previous; // first node is now the second node
	temp_node->next = stack_b->first_node; // first node is now the last node
    current_node->next = NULL; // second node is now the first node
	while (current_node)
	{
		current_node->current_position++;
		current_node = current_node->previous;
	}
	stack_b->first_node->previous = temp_node;
	temp_node->previous = NULL;
    stack_b->first_node = temp_node;
	upper_half_true_false(stack_b, data);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}
