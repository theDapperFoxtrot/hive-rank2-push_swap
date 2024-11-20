#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node *current_node;

	if (!stack->node_count)
		return (1);
	current_node = stack->first_node;
	while (current_node)
	{
		if (current_node->value < current_node->next->value)
			return (0);
		current_node = current_node->next;
	}
	return (1);
}

void	push_cheapest_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;
	t_node	*target;

	cheapest = cheapest_node(stack_a);
	target = cheapest->target;
	if (above_median(*a, cheapest) && above_median(*b, target))
		rr_and_refresh(a, b, cheapest);
	else if (!above_median(*a, cheapest) && !above_median(*b, target))
		rrr_and_refresh(a, b, cheapest);
	make_top_a(a, cheapest);
	make_top_b(b, target);
	pb(a, b);
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
	t_stack	*cheapest;
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


