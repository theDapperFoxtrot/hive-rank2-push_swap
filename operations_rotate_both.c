#include "push_swap.h"

void	rr(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
    ra(stack_a, 1, data);
    rb(stack_b, 1, data);
    is_upper_half(stack_a, stack_b, data);
    ft_putstr_fd("rr\n", 1);
}
