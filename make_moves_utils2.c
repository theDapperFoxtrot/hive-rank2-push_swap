#include "push_swap.h"

void	target_in_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_node_a;
	t_node	*current_node_b;
	t_node	*target_node;
	long	target_value;

	current_node_a = stack_a->first_node;
	while (current_node_a)
	{
		current_node_b = stack_b->first_node;
		target_value = LONG_MIN;
		while (current_node_b)
		{
			if (current_node_b->value < current_node_a->value && current_node_b->value > target_value)
			{
				target_node = current_node_b;
				target_value = current_node_b->value;
			}
			current_node_b = current_node_b->next;
		}
		if (target_value == LONG_MIN)
			target_node = stack_b->max;
		current_node_a->target = target_node;
		current_node_a = current_node_a->next;
	}
}

void target_in_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_node_a;
	t_node	*current_node_b;
	t_node	*target_node;
	long	target_value;

	current_node_b = stack_b->first_node;
	while (current_node_b)
	{
		current_node_a = stack_a->first_node;
		target_value = LONG_MAX;
		while (current_node_a)
		{
			if (current_node_a->value > current_node_b->value && current_node_a->value < target_value)
			{
				target_node = current_node_a;
				target_value = current_node_a->value;
			}
			current_node_a = current_node_a->next;
		}
		if (target_value == LONG_MAX)
			target_node = stack_a->min;
		current_node_b->target = target_node;
		current_node_b = current_node_b->next;
	}
}
void	determine_costs_both(t_stack *outbound_stack, t_stack *inbound_stack, t_node *current_node)
{
	int	current_node_position;
	int	target_node_position;
	int	count;

	current_node_position = current_node->current_position;
	target_node_position = current_node->target->current_position;
	count = 0;
	if (current_node->upper_half && current_node->target->upper_half)
		count = sim_rotations(current_node_position, target_node_position, count);
	else if (!current_node->upper_half && !current_node->target->upper_half)
	{
		current_node_position = outbound_stack->node_count - current_node_position;
		target_node_position = inbound_stack->node_count - target_node_position;
		count = sim_rotations(current_node_position, target_node_position, count);
	}
	current_node->cost = count;
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
