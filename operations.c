#include "push_swap.h"

void    sa(t_stack *stack_a)
{
	t_node  *temp;

	temp = stack_a->first_node->next; //second node stored in temp
	stack_a->first_node->next = stack_a->first_node; //second spot gets first node
	stack_a->first_node->current_position = stack_a->first_node->current_position - 1;
	stack_a->first_node = temp; //put second node into first spot
	stack_a->first_node->current_position = stack_a->first_node->current_position + 1;
// I NEED TO DRAW THIS OUT. MANY THINGS CHANGE IN THE STRUCT. POSSIBLE ABSTRACTION INTO HELPER FUNCTIONS NEEDED
}

// void    sa(t_stack *stack_a, t_stack *stack_b)
// {

// }
// void    sa(t_stack *stack_a, t_stack *stack_b)
// {

// }
// void    sa(t_stack *stack_a, t_stack *stack_b)
// {

// }
// void    sa(t_stack *stack_a, t_stack *stack_b)
// {

// }
// void    sa(t_stack *stack_a, t_stack *stack_b)
// {

// }
// void    sa(t_stack *stack_a, t_stack *stack_b)
// {

// }
// void    sa(t_stack *stack_a, t_stack *stack_b)
// {

// }
// void    sa(t_stack *stack_a, t_stack *stack_b)
// {

// }
// void    sa(t_stack *stack_a, t_stack *stack_b)
// {

// }
// void    sa(t_stack *stack_a, t_stack *stack_b)
// {

// }
// void    sa(t_stack *stack_a, t_stack *stack_b)
// {

// }