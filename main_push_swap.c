#include "push_swap.h"

// Handle memory allocation failure
void	malloc_check(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	if (!stack_a || !stack_b)
	{
		if (stack_a)
			handle_error(stack_a, data);
		if (stack_b)
			handle_error(stack_b, data);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	data;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	data.argc = argc;
	malloc_check(stack_a, stack_b, &data);
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		return (1);
	set_default_values(stack_a, stack_b, argv, &data);
	init_stack(stack_a, &data);
	make_moves(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	free_argv(&data);
	return (0);
}
