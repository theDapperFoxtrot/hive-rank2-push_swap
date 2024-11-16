#include "push_swap.h"

void	rra(t_stack *stack_a, int print, t_data *data)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (stack_a->node_count < 2)
		return ;
	temp_node = stack_a->last_node; // last node is now the first node
	temp_node->current_position = 0; // update the current position
	current_node = stack_a->last_node->previous; // first node is now the last node
	stack_a->last_node = stack_a->last_node->previous; // first node is now the second node
	temp_node->next = stack_a->first_node; // first node is now the last node
    current_node->next = NULL; // second node is now the first node
	while (current_node)
	{
		current_node->current_position++;
		current_node = current_node->previous;
	}
	stack_a->first_node->previous = temp_node;
	temp_node->previous = NULL;
    stack_a->first_node = temp_node;
	upper_half_true_false(stack_a, data);
	if (!print)
		ft_putstr_fd("rra\n", 1);
}
