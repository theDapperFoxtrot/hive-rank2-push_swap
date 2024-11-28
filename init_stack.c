#include "push_swap.h"

int	syntax_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '-' || str[i] == '+' || \
			(str[i] >= '0' && str[i] <= '9')))
			return (1);
		if ((str[i] == '-' || str[i] == '+'))
		{
			i++;
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (1);
		}
		while (str[i])
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (1);
			i++;
		}
	}
	return (0);
}

int	is_duplicate(t_stack *stack, long value)
{
	t_node	*current;

	current = stack->first_node;
	while (current != NULL)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

void	init_stack(t_stack *stack_a, t_stack *stack_b, t_data *data)
{
	int		position;
	int		i;
	long	number;

	position = 0;
	if (data->argc == 2)
		i = 0;
	else
		i = 1;
	while (data->argv[i])
	{
		number = ft_atol(data->argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			handle_error(stack_a, stack_b, data);
		if (syntax_error(data->argv[i]))
			handle_error(stack_a, stack_b, data);
		if (is_duplicate(stack_a, number))
			handle_error(stack_a, stack_b, data);
		add_node_to_stack(stack_a, create_node(number, position));
		position++;
		i++;
	}
}
