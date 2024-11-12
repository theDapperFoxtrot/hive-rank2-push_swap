#include "push_swap.h"

static void change_bfirst_fix_positions(t_stack *stack_b, t_node *current_node)
{
	stack_b->first_node = stack_b->first_node->next; //first node is now the node after the first node
	// loop and update each node's current position (decrement by 1)
	while (current_node) //while there is a node
	{
		current_node->current_position = current_node->current_position - 1; //decrement current position by 1
		current_node = current_node->next; //move to next node
	}
}

static void move_node(t_stack *stack_a, t_node *temp_node_1)
{
    	t_node  *temp_node_2;

	if (stack_a->node_count == 0) //if stack b is empty
	{
		stack_a->first_node = temp_node_1; //first node in stack b is now first node in stack a
		stack_a->last_node = temp_node_1; //last node in stack b is now first node in stack a
		stack_a->first_node->next = NULL; //next of first node in stack b is now NULL
		stack_a->first_node->previous = NULL; //previous of first node in stack b is now NULL
	}
	else //if stack b is not empty
	{
		temp_node_2 = stack_a->first_node; //first node in stack b
		stack_a->first_node = temp_node_1; //first node in stack b is now first node in stack a
		stack_a->first_node->next = temp_node_2; //next of first node in stack b is now second node in stack b
		temp_node_2->previous = stack_a->first_node; //previous of second node in stack b is now first node in stack b
	}
}

// PUSH A
void    pa(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	t_node  *current_node;
	t_node  *temp_node_1;

	if (!stack_b->first_node) //if stack is empty
		return ; //do nothing
	current_node = stack_b->first_node->next; //first node
	temp_node_1 = stack_b->first_node; //first node
    change_bfirst_fix_positions(stack_b, current_node);
    move_node(stack_a, temp_node_1);
	current_node = stack_a->first_node->next; //first node in stack b
	while (current_node) //while there is a node
	{
		current_node->current_position = current_node->current_position + 1; //decrement current position by 1
		current_node = current_node->next; //move to next node
	}
	stack_a->node_count++; //increment node count in stack b
	stack_b->node_count--; //decrement node count in stack a
	upper_half_true_false(stack_a, data);
	ft_putstr_fd("pa\n", 1);
}
