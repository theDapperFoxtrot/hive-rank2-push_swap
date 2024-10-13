#include <stdio.h>
#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}



void	error_free(t_stack_node **stack, char **argv, bool argc_2_flag)
{
	free_stack(stack);
	if (argc_2_flag)
	{
		while (*argv)
		{
			free(*argv);
			argv++;
		}
		free(argv);
	}
}

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

void	init_stack(t_stack_node **stack, char **argv, bool argc_2_flag)
{
	int		i;

	(void)stack;
	(void)argc_2_flag;
	i = 0;
	while (argv[i])
	{
		if (syntax_error(argv[i]))
			free_stack(stack);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	// t_stack_node	*stack_b;

	stack_a = NULL;
	// stack_b = NULL;
	if ((argc == 1) || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack(&stack_a, argv, 1);
	while (*argv)
	{
		printf("%s\n", stack_a->value)
		argv++;
	}
	// free_stack(&stack_a);
	return (0);
}
