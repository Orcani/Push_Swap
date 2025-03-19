#include "push_swap.h"


static void	rev_rotate(t_stack **stack) 
{ 
	t_stack	*last; 
	
	if (!*stack || !(*stack)->next) 
		return ; 
	last = ft_lstlast_ps(*stack);
	last->prev->next = NULL; 
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
	
}

void	rra(t_stack **stack_a, bool print) 
{
	rev_rotate(stack_a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack_b, bool print) 
{
	rev_rotate(stack_b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, bool print) 
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	if (!print)
		ft_printf("rrr\n");
}