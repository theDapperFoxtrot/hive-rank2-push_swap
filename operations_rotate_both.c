#include "push_swap.h"

void	rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a, 1);
    rb(stack_b, 1);
    is_upper_half(stack_a, stack_b);
    ft_putstr_fd("rr\n", 1);
}
