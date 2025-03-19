#include "push_swap.h"


static void	set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_a; 
	t_stack	*target_node; 
	long			best_match_index; 

    if (!stack_a || !stack_b)// Check if stack_a or stack_b is NULL
    {
        return;
    }
    
	while (stack_b)
	{
		best_match_index = LONG_MAX;
        target_node = NULL;  // Initialize target_node to NULL at each loop
		current_a = stack_a; 
		while (current_a) 
		{
			if (current_a->nbr > stack_b->nbr && current_a->nbr < best_match_index) 
			{
				best_match_index = current_a->nbr; 
				target_node = current_a; 
			}
			current_a = current_a->next; 
		}
		if (/*best_match_index == LONG_MAX*/ !target_node) 
			stack_b->target_node = min(stack_a); 
		else
			stack_b->target_node = target_node;
		
		stack_b = stack_b->next; 
	}
}

void	init_nodes_b(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}