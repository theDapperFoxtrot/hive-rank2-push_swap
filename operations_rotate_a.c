#include "push_swap.h"

void	ra(t_stack *stack_a, int print)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (stack_a->node_count < 2)
		return ;
	temp_node = stack_a->first_node;
	temp_node->current_position = stack_a->node_count - 1;
	current_node = stack_a->first_node->next;
	stack_a->first_node = stack_a->first_node->next;
	temp_node->next = NULL;
	current_node->previous = NULL;
	while (current_node)
	{
		current_node->current_position--;
		current_node = current_node->next;
	}
	stack_a->last_node->next = temp_node;
	temp_node->previous = stack_a->last_node;
	stack_a->last_node = temp_node;
	upper_half_true_false(stack_a);
	if (!print)
		ft_putstr_fd("ra\n", 1);
}
