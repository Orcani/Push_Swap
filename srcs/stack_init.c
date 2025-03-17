#include "push_swap.h"

t_stack	*get_cheapest(t_stack *stack) 
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node) 
	{
		if (stack_name == 'stack_a') 
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'stack_b') 
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}
}