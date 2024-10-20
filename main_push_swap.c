#include <stdio.h>
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
	malloc_check(stack_a, stack_b, &data);
	// Check if there are no arguments
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		return (1);
	// If there is only one argument, split it
	if (argc == 2)
		argc_2(stack_a, stack_b, argv, &data);
	else
		argc_above_2(stack_a, stack_b, argv, &data);
	// Initialize the stacks with nodes
	init_stack(stack_a, &data);
	// I want to test printing out the stack of integers once they've been added
	while (stack_a->first_node)
	{
		printf("%d\n", stack_a->first_node->value);
		stack_a->first_node = stack_a->first_node->next;
	}


    // Now, validate input and add nodes to the stacks
    // For example: if (validate_input(argc, argv)) { ... }
    // When done using the stacks, free them
    free_stack(stack_a);
    free_stack(stack_b);
	error_free_argv(&data);
	return (0);
}
