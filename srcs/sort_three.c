#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	t_stack	*biggest_node; 

	biggest_node = find_max(*stack_a);
	if (biggest_node == *stack_a)
		ra(stack_a, false); 
	else if ((*stack_a)->next == biggest_node) 
		rra(stack_a, false); 
	if ((*stack_a)->nbr > (*stack_a)->next->nbr) 
		sa(stack_a, false); 
}