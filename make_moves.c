#include "push_swap.h"

static void sort_more(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	if (!is_sorted(stack_a) && stack_a->node_count > 3)
		pb(stack_a, stack_b, data);
	if (!is_sorted(stack_a) && stack_a->node_count > 3)
		pb(stack_a, stack_b, data);
	while (!is_sorted(stack_a) && stack_a->node_count > 3)
	{
		target_in_b(stack_a, stack_b);
		push_cheapest_to_b(stack_a, stack_b, data);
	}
	sort_three(stack_a, data);
	while (stack_b->node_count != 0)
	{
		target_in_a(stack_a, stack_b);
		push_cheapest_to_a(stack_a, stack_b, data);
	}
	while (stack_a->min->current_position != 0)
	{
		if (stack_a->min->upper_half)
			ra(stack_a, 0, data);
		else
			rra(stack_a, 0, data);
	}
}

void	sort_three(t_stack *stack, t_data *data)
{
	int		first;
	int		second;
	int		third;

	first = stack->first_node->value;
	second = stack->first_node->next->value;
	third = stack->last_node->value;
	if (first < second && first < third && second < third)
		return ;
	else if (first < second && first < third && second > third)
	{
		sa(stack, 0, data);
		ra(stack, 0, data);
	}
	else if (first > second && first < third && second < third)
		sa(stack, 0, data);
	else if (first < second && first > third && second > third)
		rra(stack, 0, data);
	else if (first > second && first > third && second < third)
		ra(stack, 0, data);
	else if (first > second && first > third && second > third)
	{
		sa(stack, 0, data);
		rra(stack, 0, data);
	}
}

void make_moves(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	if (stack_a->node_count == 2 && stack_a->first_node->value > stack_a->last_node->value)
		sa(stack_a, 0, data);
	else if (stack_a->node_count == 3)
		sort_three(stack_a, data);
	else
		sort_more(stack_a, stack_b, data);
}
