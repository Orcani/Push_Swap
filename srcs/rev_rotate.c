#include "push_swap.h"

static void	rev_rotate(t_stack **stack) 
{
	ft_printf("test 1\n"); 
	t_stack	*last; 
	ft_printf("test 2\n"); 
	if (!*stack || !(*stack)->next) 
		return ;
	ft_printf("test 3\n"); 
	last = find_last(*stack);
	ft_printf("test 4\n"); 
	last->prev->next = NULL; //->problem
	ft_printf("test 5\n"); 
	last->next = *stack;
	ft_printf("test 6\n"); 
	last->prev = NULL;
	ft_printf("test 7\n"); 
	*stack = last; 
	ft_printf("test 8\n"); 
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