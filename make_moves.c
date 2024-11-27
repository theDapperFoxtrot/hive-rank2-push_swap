#include "push_swap.h"

static void	sort_more(t_stack *stack_a, t_stack *stack_b)
{
	if (!is_sorted(stack_a) && stack_a->node_count > 3)
		pb(stack_a, stack_b);
	if (!is_sorted(stack_a) && stack_a->node_count > 3)
		pb(stack_a, stack_b);
	while (!is_sorted(stack_a))
	{
		target_in_b(stack_a, stack_b);
		push_cheapest_to_b(stack_a, stack_b);
	}
	find_new_min_max(stack_a, stack_b);
	while (stack_b->node_count != 0)
	{
		target_in_a(stack_a, stack_b);
		push_cheapest_to_a(stack_a, stack_b);
	}
	while (stack_a->min->current_position != 0)
	{
		if (stack_a->min->upper_half)
			ra(stack_a, 0);
		else
			rra(stack_a, 0);
	}
}

void	sort_three(t_stack *stack)
{
	long		first;
	long		second;
	long		third;

	first = stack->first_node->value;
	second = stack->first_node->next->value;
	third = stack->last_node->value;
	if (first < second && first < third && second < third)
		return ;
	else if (first < second && first < third && second > third)
	{
		sa(stack, 0);
		ra(stack, 0);
	}
	else if (first > second && first < third && second < third)
		sa(stack, 0);
	else if (first < second && first > third && second > third)
		rra(stack, 0);
	else if (first > second && first > third && second < third)
		ra(stack, 0);
	else if (first > second && first > third && second > third)
	{
		sa(stack, 0);
		rra(stack, 0);
	}
}

void	make_moves(t_stack *stack_a, t_stack *stack_b)
{
	long	first_node;
	long	last_node;

	first_node = stack_a->first_node->value;
	last_node = stack_a->last_node->value;
	if (stack_a->node_count == 2 && first_node > last_node)
		sa(stack_a, 0);
	else if (stack_a->node_count == 3)
		sort_three(stack_a);
	else
		sort_more(stack_a, stack_b);
}
