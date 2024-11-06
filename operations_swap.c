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
