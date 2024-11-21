#include "push_swap.h"

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	is_upper_half(stack_a, stack_b);
	ft_putstr_fd("rrr\n", 1);
}
