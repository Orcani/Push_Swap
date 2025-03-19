#include "push_swap.h"

static void	push(t_stack **dst, t_stack **src) 
{
	t_stack	*push_node; 
	if (!src || !*src) 
		return ;
	push_node = *src; 

    *src = (*src)->next; // Move src’s top pointer to the next node
	// if ((*src)->next) //this line extra
	if (*src) 
		(*src)->prev = NULL; 
    

	push_node->prev = NULL; 
	if (!*dst) 
	{
		*dst = push_node; 
		push_node->next = NULL; 
	
	}
	else 
	{
		push_node->next = *dst;
		push_node->next->prev = push_node; 
		*dst = push_node; 
	
        // (*src) = NULL;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b, bool print) 
{
	push(stack_a, stack_b); 
	if (!print) 
		ft_printf("pa\n"); 
}

void	pb(t_stack **stack_b, t_stack **stack_a, bool print) 
{
	push(stack_b, stack_a);
	if (!print)
		ft_printf("pb\n"); //-> to modify and remove %d
}