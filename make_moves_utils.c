#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node *iterator;

	if (!stack->node_count)
		return (1);
	iterator = stack->first_node;
	while (iterator)
	{
		if (iterator->value < iterator->next->value)
			return (0);
		iterator = iterator->next;
	}
	return (1);
}

void	push_cheapest_to_b(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	t_node	*cheapest;
	t_node	*target;

	cheapest = cheapest_node(stack_a);
	target = cheapest->target;
	if (cheapest->upper_half && target->upper_half)
		while (cheapest->current_position != 0 || target->current_position != 0)
			rr(stack_a, stack_b, data);
	else if (!cheapest->upper_half && !target->upper_half)
		while (cheapest->current_position != 0 || target->current_position != 0)
			rrr(stack_a, stack_b, data);
	while (cheapest->current_position != 0)
	{
		if (cheapest->upper_half)
			ra(stack_a, 0, data);
		else
			rra(stack_a, 0, data);
		ra(stack_a, 0, data);
	}
	while (target->current_position != 0)
	{
		if (target->upper_half)
			rb(stack_b, 0, data);
		else
			rrb(stack_b, 0, data);
	}
	pb(stack_a, stack_b, data);
}

void	push_cheapest_to_a(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	t_node	*target;

	target = stack_b->cheapest->target;
	while (target->current_position != 0)
	{
		if (target->upper_half)
			ra(stack_a, 0, data);
		else
			rra(stack_a, 0, data);
	}
	pa(stack_a, stack_b, data);
}

void determine_costs(t_stack *stack)
{
	t_node	*current_node;

	if (!stack->node_count)
		return ;
	current_node = stack->first_node;
	while (current_node)
	{
		if (current_node->upper_half)
			current_node->cost = current_node->current_position;
		else
			current_node->cost = stack->node_count - current_node->current_position;
		current_node = current_node->next;
	}
}

t_node	*cheapest_node(t_stack *stack)
{
	long	min_cost;
	t_node	*cheapest;
	t_node	*current_node;

	current_node = stack->first_node;
	if (!stack->node_count)
		return (NULL);
	min_cost = LONG_MAX;
	while (current_node)
	{
		if (current_node->cost < min_cost)
		{
			cheapest = current_node;
			min_cost = current_node->cost;
		}
		current_node = current_node->next;
	}
	return (cheapest);
}


