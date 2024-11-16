#include "push_swap.h"

static void get_stuff_in_b(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
    int target_node;

    target_node = 0;
    while (target_node <= data->argc - 2)
    {
        if (stack_a->first_node->final_position == target_node)
        {
            pb(stack_a, stack_b, data);
            target_node++;
        }
        else if (stack_a->first_node->next->final_position == target_node)
        {
            sa(stack_a, 0, data);
            pb(stack_a, stack_b, data);
            target_node++;
        }
        else if (stack_a->last_node->final_position == target_node)
        {
            ra(stack_a, 0, data);
            pb(stack_a, stack_b, data);
            target_node++;
        }
        else
            rotate_a(stack_a, 0, data);
    }
}

static void get_stuff_in_a(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
    while (stack_b->node_count > 0)
        pa(stack_a, stack_b, data);
}


void make_moves(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
    get_stuff_in_b(stack_a, stack_b, data);
    get_stuff_in_a(stack_a, stack_b, data);
}
