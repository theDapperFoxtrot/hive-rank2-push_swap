#include "push_swap.h"

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_a(stack_a, 0);
	reverse_rotate_b(stack_b, 0);
	ft_putstr_fd("rrr\n", 1);
}
