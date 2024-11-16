#include "push_swap.h"

void    find_min_max(t_stack *stack_a, t_stack *stack_b)
{
	t_node *iterator = stack_a->first_node;

	stack_a->min = stack_a->first_node;
	stack_a->max = stack_a->first_node;
	while (iterator)
	{
		if (iterator->value < stack_a->min->value)
			stack_a->min = iterator;
		if (iterator->value > stack_a->max->value)
			stack_a->max = iterator;
		iterator = iterator->next;
	}
	iterator = stack_b->first_node;
	stack_b->min = stack_b->first_node;
	stack_b->max = stack_b->first_node;
	while (iterator)
	{
		if (iterator->value < stack_b->min->value)
			stack_b->min = iterator;
		if (iterator->value > stack_b->max->value)
			stack_b->max = iterator;
		iterator = iterator->next;
	}
}

int	check_if_pushed_to_b(t_stack *stack_b, int target_node)
{
	t_node *iterator = stack_b->first_node;


	while (iterator)
	{
		if (target_node == iterator->value)
			return (1);
		iterator = iterator->next;
	}
	return (0);
}

void get_stuff_in_b(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	int target_node;
	int i;

	i = 0;
	while (i <= data->argc - 2)
	{
		target_node = data->sorted_array[i];
		if (check_if_pushed_to_b(stack_b, target_node))
		{
			i++;
			target_node = data->sorted_array[i];
			continue;
		}
		if (stack_a->first_node->value == target_node)
		{
			if (stack_a->first_node->value > stack_b->max->value && stack_b->first_node->value == stack_b->max->value)
			{
				pb(stack_a, stack_b, data);
				find_min_max(stack_a, stack_b);
			}
			else if (stack_a->first_node->value < stack_b->min->value && stack_b->last_node->value == stack_b->min->value)
			{
				pb(stack_a, stack_b, data);
				rb(stack_b, 0, data);
				find_min_max(stack_a, stack_b);
			}
			i++;
		}
		else if (stack_a->first_node->next != NULL && stack_a->first_node->next->value == target_node)
			sa(stack_a, 0, data);
		else if (stack_a->last_node->value == target_node)
			rra(stack_a, 0, data);
		else
			while (stack_a->first_node->value != target_node)
				ra(stack_a, 0, data);
	}
}

void get_stuff_in_a(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	while (stack_b->node_count > 0)
		pa(stack_a, stack_b, data);
}



void make_moves(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	pb(stack_a, stack_b, data);
	pb(stack_a, stack_b, data);
	find_min_max(stack_a, stack_b);
	if (stack_b->first_node->value < stack_b->last_node->value)
		sb(stack_b, 0, data);
	get_stuff_in_b(stack_a, stack_b, data);
	get_stuff_in_a(stack_a, stack_b, data);
}
