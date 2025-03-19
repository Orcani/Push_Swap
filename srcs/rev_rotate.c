#include "push_swap.h"

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst && lst->next != NULL)
	{
		lst = lst->next;
		// ft_printf("test lst\n");
	}
		
	return (lst);
}
static void	rev_rotate(t_stack **stack) 
{
	// ft_printf("test 1\n"); 
	t_stack	*last; 
	
	// ft_printf("test 2\n"); 
	if (!*stack || !(*stack)->next) 
		return ;
	// ft_printf("test 3\n"); 
	last = ft_lstlast_ps(*stack);
	// ft_printf("test 4\n"); 
	last->prev->next = NULL; //->problem
	// ft_printf("test 5\n"); 
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
	// ptr = last;

	// if (last)
	// {
		// ft_printf("test 6\n"); 
	// 	last = last->prev;
	// 	ft_printf("test 5\n"); 
	// 	last->next = NULL;
	// } 
	// ft_printf("test 6\n"); 
	// ptr->next = *stack;
	// (*stack)->prev = ptr;
	// ptr->prev = NULL;
	// ft_printf("test 7\n"); 
	
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