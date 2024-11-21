#include "push_swap.h"

static void assign_final_position(t_stack *stack_a, int value, int index)
{
	t_node *iterator = stack_a->first_node;

	while (iterator)
	{
		if (iterator->value == value)
		{
			iterator->final_position = index;
		}
		iterator = iterator->next;
	}
}

static void sort_array(t_stack *stack_a, t_data *data)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < data->argc - 1)
	{
		j = i + 1;
		while (j < data->argc - 1)
		{
			if (data->sorted_array[i] > data->sorted_array[j])
			{
				temp = data->sorted_array[i];
				data->sorted_array[i] = data->sorted_array[j];
				data->sorted_array[j] = temp;
			}
			j++;
		}
		assign_final_position(stack_a, data->sorted_array[i], i);
		i++;
	}
}


void sorting(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	sort_array(stack_a, data);
	is_upper_half(stack_a, stack_b);
}