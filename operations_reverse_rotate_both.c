#include "push_swap.h"

void	rrr(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	rra(stack_a, 0, data);
	rrb(stack_b, 0, data);
	is_upper_half(stack_a, stack_b, data);
	ft_putstr_fd("rrr\n", 1);
}
