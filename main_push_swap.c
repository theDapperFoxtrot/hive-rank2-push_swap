#include "push_swap.h"

void	malloc_check(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	if (!stack_a || !stack_b)
    {
        // Handle memory allocation failure
        if (stack_a)
			handle_error(stack_a, data);
        if (stack_b)
			handle_error(stack_b, data);
    }
}

int	main(int argc, char **argv)
{
	t_stack *stack_a = (t_stack *)malloc(sizeof(t_stack));
    t_stack *stack_b = (t_stack *)malloc(sizeof(t_stack));
	t_data	data;

	data.argc = argc;
	data.sorted_array = (long *)malloc(data.argc * sizeof(long));
	if (data.sorted_array == NULL)
	{
    ft_putstr_fd("Error: Memory allocation failed for sorted_array\n", 2);
    exit(1);
	}
	malloc_check(stack_a, stack_b, &data);
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		return (1);
	set_default_values(stack_a, stack_b, argv, &data);
	init_stack(stack_a, &data);
	sorting(stack_a, stack_b, &data);
	make_moves(stack_a, stack_b);
	free(data.sorted_array);
    free_stack(stack_a);
    free_stack(stack_b);
	free_argv(&data);
	return (0);
}
