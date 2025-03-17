#include "push_swap.h"


int	stack_len(t_stack *stack) 
{
	int	count; 

	if (!stack) 
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack	*find_last(t_stack *stack) 
{
	if (!stack)
		return (NULL);
	while (stack->next) 
		stack = stack->next;
	return (stack);
}

bool	sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next) 
	{
		if (stack->nbr > stack->next->nbr) 
			return (false);
		stack = stack->next; 
	}
	return (true);
}

t_stack	*min(t_stack *stack) 
{
	long		minim;
	t_stack *min_node ;  

	if (!stack)
		return (NULL);
	minim = LONG_MAX; 
	while (stack)
	{
		if (stack->nbr < minim) 
		{
			minim = stack->nbr;
			min_node = stack; 
		}
		stack = stack->next;
	}
	return (min_node); 
}

t_stack	*max(t_stack *stack) 
{
	long			maxi;
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	maxi = LONG_MIN; 
	while (stack)
	{
		if (stack->nbr > maxi)
		{
			maxi = stack->nbr;
			max_node = stack; 
		}
		stack = stack->next;
	}
	return (max_node);
}