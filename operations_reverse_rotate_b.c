#include "push_swap.h"

static void position_fix(t_node *current_node)
{
	int position;

	position = 1;
    while (current_node)
    {
        current_node->current_position = position++;
        current_node = current_node->next;
    }
}

void	rrb(t_stack *stack_b, int print)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (stack_b->node_count < 2)
		return ;

	temp_node = stack_b->last_node; // last node is now the first node
	temp_node->current_position = 0; // update the current position
	stack_b->last_node = stack_b->last_node->previous; // second to last node is now the last node
	stack_b->last_node->next = NULL; // first node is now the second node

	temp_node->next = stack_b->first_node; // first node is now the last node
    stack_b->first_node->previous = temp_node; // first node is now the last node
	stack_b->first_node = temp_node; // first node is now the last node
	stack_b->first_node->previous = NULL; // first node is now the last node

	current_node = stack_b->first_node->next; // second node is now the first node
	position_fix(current_node);
	upper_half_true_false(stack_b);
	if (!print)
		ft_putstr_fd("rrb\n", 1);
}
