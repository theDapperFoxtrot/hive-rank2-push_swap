#include "push_swap.h"

int	sim_rotations(int current_node_position, int target_node_position, int count)
{
	while (current_node_position != 0 || target_node_position != 0)
	{
		if (current_node_position == 0 || target_node_position == 0)
			break ;
		current_node_position--;
		target_node_position--;
		count++;
	}
	while (current_node_position != 0)
	{
		current_node_position--;
		count++;
	}
	while (target_node_position != 0)
	{
		target_node_position--;
		count++;
	}
	return (count);
}

