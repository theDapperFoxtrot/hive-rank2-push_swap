#include "push_swap.h"

#include <stdio.h>

void	handle_error(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	if (data->argv != NULL)
		free_argv(data);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->first_node;
	while (current)
	{
		next = current->next;
		free(current);
		current = NULL;
		current = next;
	}
	free(stack);
	stack = NULL;
}

void	free_argv(t_data *data)
{
	int	i;

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
