#include "push_swap.h"

static void	position_fix(t_node *current_node)
{
	int	position;

	position = 1;
	while (current_node)
	{
		current_node->current_position = position++;
		current_node = current_node->next;
	}
}

void	rra(t_stack *stack_a, int print)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (stack_a->node_count < 2)
		return ;
	temp_node = stack_a->last_node;
	temp_node->current_position = 0;
	stack_a->last_node = stack_a->last_node->previous;
	stack_a->last_node->next = NULL;
	temp_node->next = stack_a->first_node;
	stack_a->first_node->previous = temp_node;
	stack_a->first_node = temp_node;
	stack_a->first_node->previous = NULL;
	current_node = stack_a->first_node->next;
	position_fix(current_node);
	upper_half_true_false(stack_a);
	if (!print)
		ft_putstr_fd("rra\n", 1);
}
