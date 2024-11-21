#include "push_swap.h"

void    find_new_min_max(t_stack *stack_a, t_stack *stack_b)
{
    t_node  *current_node;

    current_node = stack_a->first_node;
    stack_a->min = current_node;
    stack_a->max = current_node;
    while (current_node)
    {
        if (current_node->value < stack_a->min->value)
            stack_a->min = current_node;
        if (current_node->value > stack_a->max->value)
            stack_a->max = current_node;
        current_node = current_node->next;
    }
    current_node = stack_b->first_node;
    stack_b->min = current_node;
    stack_b->max = current_node;
    while (current_node)
    {
        if (current_node->value < stack_b->min->value)
            stack_b->min = current_node;
        if (current_node->value > stack_b->max->value)
            stack_b->max = current_node;
        current_node = current_node->next;
    }
}