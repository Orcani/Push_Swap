#include "push_swap.h"

void	sort_three(t_stack **stack_a /*, t_stack **stack_b*/)
{
	t_stack	*biggest_node; 
	// display(stack_b);
	biggest_node = max(*stack_a);
	if (biggest_node == *stack_a)
		ra(stack_a, false); 
	else if ((*stack_a)->next == biggest_node) 
		rra(stack_a, false); 
	// ft_printf("nbr %d\n",(*stack_a)->nbr );
	// ft_printf("nbr next %d\n", (*stack_a)->next->nbr ); // -> seg
	if ((*stack_a)->nbr > (*stack_a)->next->nbr) 
		sa(stack_a, false); 
	
}