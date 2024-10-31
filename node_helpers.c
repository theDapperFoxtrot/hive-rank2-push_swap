#include "push_swap.h"

#include <stdio.h>

t_node *create_node(int value, int position)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));
	// printf("malloc %p\n", new_node);
	if (!new_node)
		return NULL;  // Handle malloc failure

	new_node->value = value;
	new_node->current_position = position;
	new_node->upper_half = false;
	new_node->final_position = 0;
	new_node->push_price = 0;
	new_node->next = NULL;
	new_node->previous = NULL;
	return new_node;
}

void add_node_to_stack(t_stack *stack, t_node *new_node)
{
	if (stack->node_count == 0)
	{
		stack->first_node = new_node;
		stack->last_node = new_node;
	}
	else
	{
		stack->last_node->next = new_node;
		new_node->previous = stack->last_node;
		stack->last_node = new_node;
	}
	stack->node_count++;
}
