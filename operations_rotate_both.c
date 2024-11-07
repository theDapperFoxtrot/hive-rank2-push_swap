#include "push_swap.h"

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
    rotate_a(stack_a, 0);
    rotate_b(stack_b, 0);
    ft_putstr_fd("rr\n", 1);
}
