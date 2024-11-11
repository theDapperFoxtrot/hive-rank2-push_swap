#include "push_swap.h"


// FIX THIS FUNCTION
static int	*sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	k;
	int	biggest;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				biggest = array[i];
				k = i;
			}
			j++;
		}
		array[k] = array[j];
		array[j] = biggest;
		i++;
	}
	return (array);
}

void sorting(t_stack *stack_a, t_stack *stack_b, t_data *data)
{

	(void)stack_a;
	(void)stack_b;

	data->sorted_array = sort_array(data->sorted_array, data->argc - 1);
}