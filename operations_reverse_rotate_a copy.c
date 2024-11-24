#include "push_swap.h"

static void	fix_positions(t_stack *stack)
{
	t_node	*current_node;
	int		position;

	current_node = stack->first_node;
	position = 0;
	while (current_node)
	{
		current_node->current_position = position;
		position++;
		current_node = current_node->next;
	}
}

void	rra(t_stack *stack_a, int print)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (stack_a->node_count < 2)
		return ;
	temp_node = stack_a->last_node; // last node is now the first node
	temp_node->current_position = 0; // update the current position
	current_node = stack_a->first_node->next; // first node is now the last node
	current_node->previous = stack_a->first_node;
    current_node->next = NULL; // second node is now the first node
	stack_a->last_node = stack_a->last_node->previous; // first node is now the second node
	temp_node->next = stack_a->first_node; // first node is now the last node
	stack_a->first_node->previous = temp_node;
	temp_node->previous = NULL;
    stack_a->first_node = temp_node;
	fix_positions(stack_a);
	upper_half_true_false(stack_a);
	if (!print)
		ft_putstr_fd("rra\n", 1);
}
