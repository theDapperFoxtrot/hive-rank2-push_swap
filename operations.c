#include "push_swap.h"

void    sa(t_stack *stack_a)
{
	t_node  *temp_node1;
	t_node  *temp_node2;

	//STORAGE
	temp_node1 = stack_a->first_node; //first node
	temp_node2 = stack_a->first_node->next; //second node
	//CHANGE node1 info
	temp_node1->next = stack_a->first_node->next->next; //node1 next is now node3
	temp_node1->previous = stack_a->first_node->next; //node1 previous is now node2
	temp_node1->current_position = temp_node1->current_position + 1; //node1 current position is now 2
	//CHANGE node2 info
	temp_node2->next = stack_a->first_node; //node2 next is now node1
	temp_node2->previous = NULL; //node2 previous is now NULL
	temp_node2->current_position = temp_node2->current_position - 1; //node1 current position is now 2
	//SWAP first and scond node
	stack_a->first_node = temp_node2; //node2 is now first node
	}

void    sb(t_stack *stack_b)
{
	t_node  *temp_node1;
	t_node  *temp_node2;

	//STORAGE
	temp_node1 = stack_b->first_node; //first node
	temp_node2 = stack_b->first_node->next; //second node
	//CHANGE node1 info
	temp_node1->next = stack_b->first_node->next->next; //node1 next is now node3
	temp_node1->previous = stack_b->first_node->next; //node1 previous is now node2
	temp_node1->current_position = temp_node1->current_position + 1; //node1 current position is now 2
	//CHANGE node2 info
	temp_node2->next = stack_b->first_node; //node2 next is now node1
	temp_node2->previous = NULL; //node2 previous is now NULL
	temp_node2->current_position = temp_node2->current_position - 1; //node1 current position is now 2
	//SWAP first and scond node
	stack_b->first_node = temp_node2; //node2 is now first node
	}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
// PUSH A
// void    pa(t_stack *stack_a, t_stack *stack_b)
// {

// }

// PUSH B
void    pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node  *current_node;
	t_node  *temp_node_a;
	t_node  *temp_node_b;

	if (!stack_a->first_node) //if stack is empty
		return ; //do nothing

	current_node = stack_a->first_node->next; //first node
	temp_node_a = stack_a->first_node; //first node

	stack_a->first_node = stack_a->first_node->next; //first node is now the node after the first node
	// loop and update each node's current position (decrement by 1)
	while (current_node) //while there is a node
	{
		current_node->current_position = current_node->current_position - 1; //decrement current position by 1
		current_node = current_node->next; //move to next node
	}

	if (stack_b->node_count == 0) //if stack b is empty
	{
		stack_b->first_node = temp_node_a; //first node in stack b is now first node in stack a
		stack_b->last_node = temp_node_a; //last node in stack b is now first node in stack a
		stack_b->first_node->next = NULL; //next of first node in stack b is now NULL
		stack_b->first_node->previous = NULL; //previous of first node in stack b is now NULL
	}
	else //if stack b is not empty
	{
		temp_node_b = stack_b->first_node; //first node in stack b
		stack_b->first_node = temp_node_a; //first node in stack b is now first node in stack a
		stack_b->first_node->next = temp_node_b; //next of first node in stack b is now second node in stack b
		temp_node_b->previous = stack_b->first_node; //previous of second node in stack b is now first node in stack b
	}
	current_node = stack_b->first_node->next; //first node in stack b
	while (current_node) //while there is a node
	{
		current_node->current_position = current_node->current_position + 1; //decrement current position by 1
		current_node = current_node->next; //move to next node
	}

	stack_b->node_count++; //increment node count in stack b
	stack_a->node_count--; //decrement node count in stack a
}

// ROTATE A
// void    sa(t_stack *stack_a)
// {

// }

// ROTATE B
// void    sa(t_stack *stack_b)
// {

// }

// ROTATE BOTH
// void    sa(t_stack *stack_a, t_stack *stack_b)
// {

// }

// REVERSE ROTATE A
// void    sa(t_stack *stack_a)
// {

// }

// REVERSE ROTATE B
// void    sa(t_stack *stack_b)
// {

// }

// REVERSE ROTATE BOTH
// void    sa(t_stack *stack_a, t_stack *stack_b)
// {

// }
