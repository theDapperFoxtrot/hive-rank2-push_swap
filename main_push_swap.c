#include "push_swap.h"

#include <stdio.h>

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
	char	***temp_argv;
	int		i;

	i = 0;
	data.argc = argc;
	malloc_check(stack_a, stack_b, &data);
	// Check if there are no arguments
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		return (1);
	// Split the arguments
	while (i < argc - 1)
	{
		temp_argv[i] = ft_split(argv[i + 1], ' ');
		i++;
	}
	// then I need to join these, and free this abomination
	set_default_values(stack_a, stack_b, argv, &data);
	// Initialize the stacks with nodes
	init_stack(stack_a, &data);
	// I want to test printing out the stack of integers once they've been added
	t_node *iterator = stack_a->first_node;
	while (iterator)
	{
		printf("%d\n", iterator->value);
		iterator = iterator->next;
	}


    // Now, validate input and add nodes to the stacks
    // For example: if (validate_input(argc, argv)) { ... }
    // When done using the stacks, free them
    free_stack(stack_a);
    free_stack(stack_b);
	error_free_argv(&data);
	return (0);
}
