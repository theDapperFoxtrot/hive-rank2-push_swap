#include "push_swap.h"

int	syntax_error(char *str)
{
	while (*str)
	{
		if (!(*str == '-' || *str == '+' || (*str >= '0' && *str <= '9')))
			return (1);
		if ((*str == '-' || *str == '+') && (!(*str + 1 >= '0' && *str + 1 <= '9')))
			return (1);
		while (*++str)
		{
			if (!(*str >= '0' && *str <= '9'))
				return (1);
		}
	}
	return (0);
}

int	is_duplicate(t_stack *stack, long value)
{
	t_node *current = stack->first_node;

	while (current != NULL)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

void	init_stack(t_stack *stack, t_data *data)
{
	long	number;
	int		i;

	if (data->argc == 2)
		i = 0;
	else
		i = 1;
	while (data->argv[i])
	{
		number = ft_atol(data->argv[i]);
		if (syntax_error(data->argv[i]))
			handle_error(stack, data);
		if (is_duplicate(stack, number))
			handle_error(stack, data);
		add_node_to_stack(stack, create_node((int) number));
		i++;
	}
}
