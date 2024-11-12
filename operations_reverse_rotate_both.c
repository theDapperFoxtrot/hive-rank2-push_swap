#include "push_swap.h"

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	reverse_rotate_a(stack_a, 0, data);
	reverse_rotate_b(stack_b, 0, data);
	is_upper_half(stack_a, stack_b, data);
	ft_putstr_fd("rrr\n", 1);
}
