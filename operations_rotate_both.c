#include "push_swap.h"

void	rr(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
    ra(stack_a, 0, data);
    rb(stack_b, 0, data);
    is_upper_half(stack_a, stack_b, data);
    ft_putstr_fd("rr\n", 1);
}
