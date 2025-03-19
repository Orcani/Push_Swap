#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	t_stack	*biggest_node; 

	biggest_node = max(*stack_a);
	if (biggest_node == *stack_a)
		ra(stack_a, false); 
	else if ((*stack_a)->next == biggest_node) 
		rra(stack_a, false); 
	if ((*stack_a)->nbr > (*stack_a)->next->nbr) 
		sa(stack_a, false); 
}

// void	sort_five(t_stack **stack_a, t_stack **stack_b)
// {
// 	while (stack_len(*stack_a) > 3)
// 	{
// 		init_nodes(*stack_a, *stack_b);
// 		finish_rotation(stack_a, min(*stack_a), 'a');
// 		pb(stack_b, stack_a, false);
// 	}
// }