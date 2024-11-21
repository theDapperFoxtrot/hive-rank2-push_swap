#include "push_swap.h"

void	target_in_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_node_a;
	t_node	*current_node_b;
	t_node	*target;

	current_node_a = stack_a->first_node; // set the current node in stack_a to the first node
	while (current_node_a) // while the current node in stack_a is not NULL
	{
		target = LONG_MAX; // set the target to the maximum value of a long
		current_node_b = stack_b->first_node; // set the current node in stack_b to the first node
		while (current_node_b) // while the current node in stack_b is not NULL
		{
			if (current_node_b->value < current_node_a->value && current_node_b->value > target->value) // if the value is smaller than the current value in stack_a and bigger than the target value
				target = current_node_b; // set the target to the current node in stack_b
			current_node_b = current_node_b->next; // move to the next node in stack_b
		}
		current_node_a->target = target; // set the target of the current node in stack_a to the target
		current_node_a = current_node_a->next; // move to the next node in stack_a
	}
}
void	target_in_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_node_a;
	t_node	*current_node_b;
	t_node	*target;

	current_node_b = stack_b->first_node; // set the current node in stack_b to the first node
	while (current_node_b) // while the current node in stack_b is not NULL
	{
		target = LONG_MAX; // set the target to the maximum value of a long
		current_node_a = stack_a->first_node; // set the current node in stack_a to the first node
		while (current_node_a) // while the current node in stack_a is not NULL
		{
			if (current_node_a->value > current_node_b->value && current_node_a->value < target->value) // if the value is bigger than the current value in stack_b and smaller than the target value
				target = current_node_a; // set the target to the current node in stack_a
			current_node_a = current_node_a->next; // move to the next node in stack_a
		}
		current_node_b->target = target; // set the target of the current node in stack_b to the target
		current_node_b = current_node_b->next; // move to the next node in stack_b
	}
}
