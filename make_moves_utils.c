#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*iterator;

	if (!stack->node_count)
		return (1);
	iterator = stack->first_node;
	while (iterator && iterator->next)
	{
		if (iterator->value > iterator->next->value)
			return (0);
		iterator = iterator->next;
	}
	return (1);
}

void	push_cheapest_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;
	t_node	*target;

	determine_costs(stack_a, stack_b);
	cheapest = cheapest_node(stack_a);
	target = cheapest->target;
	handle_double_rots(stack_a, stack_b, cheapest, target);
	while (cheapest->current_position != 0)
	{
		if (cheapest->upper_half)
			ra(stack_a, 0);
		else
			rra(stack_a, 0);
	}
	while (target->current_position != 0)
	{
		if (target->upper_half)
			rb(stack_b, 0);
		else
			rrb(stack_b, 0);
	}
	pb(stack_a, stack_b);
}

void	push_cheapest_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;
	t_node	*target;

	determine_costs(stack_b, stack_a);
	cheapest = cheapest_node(stack_b);
	target = cheapest->target;
	handle_double_rots(stack_a, stack_b, cheapest, target);
	while (target->current_position != 0)
	{
		if (target->upper_half)
			ra(stack_a, 0);
		else
			rra(stack_a, 0);
	}
	pa(stack_a, stack_b);
}

void	determine_costs(t_stack *outbound_stack, t_stack *inbound_stack)
{
	t_node	*current_node;

	if (!outbound_stack->node_count)
		return ;
	current_node = outbound_stack->first_node;
	while (current_node)
	{
		current_node->cost = 0;
		current_node = current_node->next;
	}
	current_node = outbound_stack->first_node;
	while (current_node)
	{
		if ((current_node->upper_half && current_node->target->upper_half) \
			|| (!current_node->upper_half && !current_node->target->upper_half))
			determine_costs_both(outbound_stack, inbound_stack, current_node);
		else
			determine_costs_ind(outbound_stack, inbound_stack, current_node);
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
