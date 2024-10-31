#include "push_swap.h"

#include <stdio.h>

static void postion_finder_backward(t_stack *stack, t_data *data)
{
	t_node	*current;
	t_node	*biggest;
	int		index;

	index = data->argc - 1;
	// printf("THE BIGGEST PRE-SORT:\n");
	while (index)
	{
		current = stack->first_node;
		// printf("loop #%d\n", index);
		biggest = current;
		while (current)
		{
			// printf("current value: %d\n", current->value);
			if (current->value > biggest->value && current->pre_sorted == 0)
				biggest = current;
			current = current->next;
		}
		// printf("\nbiggest value: %d\n", biggest->value);
		biggest->final_position = index - 1;
		biggest->pre_sorted = 1;
		// printf("Should be placed at index: %d\n\n", biggest->final_position);
		index--;
	}
}

static void postion_finder_forward(t_stack *stack, t_data *data)
{
	t_node	*current;
	t_node	*smallest;
	int		index;

	index = 0;
	printf("THE SMALLEST PRE-SORT:\n");
	while (index < data->argc - 1)
	{
		current = stack->first_node;
		printf("loop #%d\n", index);
		smallest = current;
		while (current)
		{
			if (current->pre_sorted == 0)
				printf("current value: %d\n", current->value);
			// if (current->pre_sorted == 1)
			// {
			// 	current = current->next;
			// 	continue;
			// }
			if (current->value < smallest->value && current->pre_sorted == 0)
				smallest = current;
			current = current->next;
		}
		printf("\nsmallest value: %d\n", smallest->value);
		smallest->final_position = (data->argc - 1) - (index + 1);
		smallest->pre_sorted = 1;
		printf("Should be placed at index: %d\n\n", smallest->final_position);
		index++;
	}
}


void	final_position_finder(t_stack *stack, t_data *data)
{
	postion_finder_backward(stack, data);
	postion_finder_forward(stack, data);
}
