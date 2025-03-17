#include "push_swap.h"


static void	push(t_stack **dst, t_stack **src) 
{
	t_stack	*push_node; 

	if (!*src) 
		return ;
	push_node = *src; 
	if ((*src)->next) //this line extra
		*src = (*src)->next;//this line extra
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
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b, bool print) 
{
	push(stack_a, stack_b); 
	if (!print) 
		ft_printf("pa a: %d b: %d\n", (*stack_a)->nbr, (*stack_b)->nbr); //-> to modify and remove %d
}

void	pb(t_stack **stack_b, t_stack **stack_a, bool print) 
{
	push(stack_b, stack_a);
	if (!print)
		ft_printf("pb b: %d a: %d\n", (*stack_b)->nbr, (*stack_a)->nbr); //-> to modify and remove %d
}