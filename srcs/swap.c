#include "push_swap.h"

static void	swap(t_stack **head) 
{
	if (!*head || !(*head)->next) 
		return ;
	*head = (*head)->next;
    // if ((*head)->prev->prev != NULL) //->voir si c'est vraiment utile
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next; 
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev; 
	(*head)->next = (*head)->prev; 
	(*head)->prev = NULL; 
}

void	sa(t_stack	**stack_a, bool print) 
{
	swap(stack_a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_stack **stack_b, bool print) 
{
	swap(stack_b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b, bool print) 
{
	swap(stack_a);
	swap(stack_b);
	if (!print)
		ft_printf("ss\n");
}