#include "push_swap.h"

#include <stdio.h>

void handle_error(t_stack *stack, t_data *data)
{
	if (stack)
		free_stack(stack);
	error_free_argv(data);
	ft_putstr_fd("Error\n", 2);
	exit(1);
	// Additional error handling (e.g., print error message)
}

void	free_stack(t_stack *stack)
{
	t_node *current = stack->first_node;
	t_node *next;

	while (current != NULL)
	{
		next = current->next;
		// printf("free %p\n", current);
		free(current);  // Free the current node
		current = next;
	}
	free(stack);  // Free the stack structure
}

void	error_free_argv(t_data *data)
{
	int i;

	i = 0;
	if (data->argc == 2)
	{
		while (data->argv[i])
		{
			free(data->argv[i]);
			data->argv[i] = NULL;
			i++;
		}
		free(data->argv);
		data->argv = NULL;
	}
}
