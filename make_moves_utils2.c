#include "push_swap.h"

void	target_in_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_node_a;
	t_node	*current_node_b;
	t_node	*target_node;
	long	target_value;

	current_node_a = stack_a->first_node; // set the current node in stack_a to the first node
	while (current_node_a) // while the current node in stack_a is not NULL
	{
		current_node_b = stack_b->first_node; // set the current node in stack_b to the first node
		target_value = LONG_MIN; // set the target value to the minimum value of a long
		while (current_node_b) // while the current node in stack_b is not NULL
		{
			if (current_node_b->value < current_node_a->value && current_node_b->value > target_value) // if the value is smaller than the current value in stack_a and bigger than the target value
			{
				target_value = current_node_b->value; // set the target value to the value of the current node in stack_b
				target_node = current_node_b; // set the target to the current node in stack_b
			}
			current_node_b = current_node_b->next; // move to the next node in stack_b
		}
		if (target_value == LONG_MIN) // if the target value is still the minimum value of a long
			target_node = stack_b->max; // set the target to the minimum value in stack_b
		current_node_a->target = target_node; // set the target of the current node in stack_a to the target
		current_node_a = current_node_a->next; // move to the next node in stack_a
	}
}

void target_in_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_node_a;
	t_node	*current_node_b;
	t_node	*target_node;
	long	target_value;

	current_node_b = stack_b->first_node; // set the current node in stack_b to the first node
	while (current_node_b) // while the current node in stack_b is not NULL
	{
		current_node_a = stack_a->first_node; // set the current node in stack_a to the first node
		target_value = LONG_MAX; // set the target value to the minimum value of a long
		while (current_node_a) // while the current node in stack_a is not NULL
		{
			if (current_node_a->value > current_node_b->value && current_node_a->value > target_value) // if the value is bigger than the current value in stack_b and bigger than the target value
			{
				target_node = current_node_a; // set the target to the current node in stack_a
				target_value = current_node_a->value; // set the target value to the value of the current node in stack_a
			}
			current_node_a = current_node_a->next; // move to the next node in stack_a
		}
		if (target_value == LONG_MAX) // if the target value is still the maximum value of a long
			target_node = stack_a->min; // set the target to the minimum value in stack_a
		current_node_b->target = target_node; // set the target of the current node in stack_b to the target
		current_node_b = current_node_b->next; // move to the next node in stack_b
	}
}
void	determine_costs_both(t_stack *outbound_stack, t_stack *inbound_stack, t_node *current_node)
{
		if (current_node->upper_half && current_node->target->upper_half)
		{
			current_node->cost = current_node->current_position;
			current_node->cost += current_node->target->current_position;
		}
		else if (!current_node->upper_half && !current_node->target->upper_half)
		{
			current_node->cost = outbound_stack->node_count - current_node->current_position;
			current_node->cost += inbound_stack->node_count - current_node->target->current_position;
		}
}

void	determine_costs_ind(t_stack *outbound_stack, t_stack *inbound_stack, t_node *current_node)
{
		if (current_node->upper_half && !current_node->target->upper_half)
		{
			current_node->cost = current_node->current_position;
			current_node->cost += inbound_stack->node_count - current_node->target->current_position;
		}
		else if (!current_node->upper_half && current_node->target->upper_half)
		{
			current_node->cost = outbound_stack->node_count - current_node->current_position;
			current_node->cost += current_node->target->current_position;
		}
}
