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

	data.argc = argc;
	malloc_check(stack_a, stack_b, &data);
	// Check if there are no arguments
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		// Split the arguments
			data.argv = ft_split(argv[1], ' ');
	}
	set_default_values(stack_a, stack_b, argv, &data);
	// Initialize the stacks with nodes
	init_stack(stack_a, &data);
	// I want to test printing out the stack of integers once they've been added
	t_node *iterator_a = stack_a->first_node;
	// t_node *iterator_b = stack_b->first_node;
	printf("\n--------------NODES_A:\n");
	printf("%d\n\n", stack_a->node_count);
	while (iterator_a)
	{
		printf("value: %d\n", iterator_a->value);
		printf("current_position: [%d]\n", iterator_a->current_position);
		printf("next: %p\n", iterator_a->next);
		if (iterator_a->next)
			printf("current: %p\n", iterator_a->next->previous);
		printf("previous: %p\n\n", iterator_a->previous);
		iterator_a = iterator_a->next;
	}

	// pb(stack_a, stack_b);
	// pb(stack_a, stack_b);
	// pa(stack_a, stack_b);
	rotate_a(stack_a);

	iterator_a = stack_a->first_node;
	printf("\n----------------NODES_A AFTER Push:\n");
	printf("%d\n\n", stack_a->node_count);
	while (iterator_a)
	{
		printf("value: %d\n", iterator_a->value);
		printf("current_position: [%d]\n", iterator_a->current_position);
		printf("next: %p\n", iterator_a->next);
		if (iterator_a->next)
			printf("current: %p\n", iterator_a->next->previous);
		printf("previous: %p\n\n", iterator_a->previous);
		iterator_a = iterator_a->next;
	}

	// iterator_b = stack_b->first_node;
	// printf("\n------------------NODES_B:\n");
	// printf("%d\n\n", stack_b->node_count);
	// while (iterator_b)
	// {
	// 	printf("value: %d\n", iterator_b->value);
	// 	// printf("final_position: [%d]\n", iterator_b->final_position);
	// 	printf("current_position: [%d]\n", iterator_b->current_position);
	// 	// printf("upper_half: %d\n", iterator_b->upper_half);
	// 	// printf("push_price: %d\n", iterator_b->push_price);
	// 	printf("next: %p\n", iterator_b->next);
	// 	if (iterator_b->next)
	// 		printf("current: %p\n", iterator_b->next->previous);
	// 	printf("previous: %p\n\n", iterator_b->previous);
	// 	iterator_b = iterator_b->next;
	// }

    // Now, validate input and add nodes to the stacks
    // For example: if (validate_input(argc, argv)) { ... }
    // When done using the stacks, free them
    free_stack(stack_a);
    free_stack(stack_b);
	error_free_argv(&data);
	return (0);
}
