#include "push_swap.h"

void	sa(t_stack *stack_a, int print)
{
	t_node	*temp_node1;
	t_node	*temp_node2;

	temp_node1 = stack_a->first_node;
	temp_node2 = stack_a->first_node->next;
	temp_node1->previous = stack_a->first_node->next;
	temp_node1->next = stack_a->first_node->next->next;
	temp_node1->current_position = temp_node1->current_position + 1;
	temp_node2->next = stack_a->first_node;
	temp_node2->previous = NULL;
	temp_node2->current_position = temp_node2->current_position - 1;
	stack_a->first_node = temp_node2;
	if (stack_a->node_count == 2)
		stack_a->last_node = temp_node1;
	upper_half_true_false(stack_a);
	if (!print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack_b, int print)
{
	t_node	*temp_node1;
	t_node	*temp_node2;

	temp_node1 = stack_b->first_node;
	temp_node2 = stack_b->first_node->next;
	temp_node1->previous = stack_b->first_node->next;
	temp_node1->next = stack_b->first_node->next->next;
	temp_node1->current_position = temp_node1->current_position + 1;
	temp_node2->next = stack_b->first_node;
	temp_node2->previous = NULL;
	temp_node2->current_position = temp_node2->current_position - 1;
	stack_b->first_node = temp_node2;
	if (stack_b->node_count == 2)
		stack_b->last_node = temp_node1;
	upper_half_true_false(stack_b);
	if (!print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	is_upper_half(stack_a, stack_b);
	ft_putstr_fd("ss\n", 1);
}
