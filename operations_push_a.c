#include "push_swap.h"

static void	change_bfirst_fix_positions(t_stack *stack_b, t_node *current_node)
{
	stack_b->first_node = stack_b->first_node->next;
	while (current_node)
	{
		current_node->current_position = current_node->current_position - 1;
		current_node = current_node->next;
	}
}

static void	move_node(t_stack *stack_a, t_node *temp_node_1)
{
	t_node	*temp_node_2;

	if (stack_a->node_count == 0)
	{
		stack_a->first_node = temp_node_1;
		stack_a->last_node = temp_node_1;
		stack_a->first_node->next = NULL;
		stack_a->first_node->previous = NULL;
	}
	else
	{
		temp_node_2 = stack_a->first_node;
		stack_a->first_node = temp_node_1;
		stack_a->first_node->next = temp_node_2;
		temp_node_2->previous = stack_a->first_node;
		while (temp_node_2->next)
		{
			temp_node_2->next->previous = temp_node_2;
			temp_node_2 = temp_node_2->next;
		}
	}
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_node;
	t_node	*temp_node_1;

	if (!stack_b->first_node)
		return ;
	current_node = stack_b->first_node->next;
	temp_node_1 = stack_b->first_node;
	change_bfirst_fix_positions(stack_b, current_node);
	move_node(stack_a, temp_node_1);
	current_node = stack_a->first_node->next;
	while (current_node)
	{
		current_node->current_position = current_node->current_position + 1;
		current_node = current_node->next;
	}
	stack_a->node_count++;
	stack_b->node_count--;
	is_upper_half(stack_a, stack_b);
	find_new_min_max(stack_a, stack_b);
	ft_putstr_fd("pa\n", 1);
}
