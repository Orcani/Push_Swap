/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 20:36:02 by desambou          #+#    #+#             */
/*   Updated: 2025/03/03 17:08:57 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack **stack_a)
{
    t_stack *first;
    t_stack *second;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;
    first = *stack_a;
    second = first->next;
    
    first->next = second->next;
    second->next = first;
    *stack_a = second;
	ft_printf("sa\n");
}

void ra(t_stack **stack_a)
{
    t_stack *first;
    t_stack *last;
    t_stack *current;

    if(*stack_a == NULL || (*stack_a)->next == NULL || (*stack_a)->next->next == NULL)
        return;
    first = *stack_a;
    current = first->next;
    while (current->next !=NULL)
        current = current->next;
    last = current;
    *stack_a= first->next;
    last->next = first;
    first->next = NULL;
	ft_printf("ra\n");
}
void rb(t_stack **stack_b)
{
    t_stack *first;
    t_stack *last;
    t_stack *current;

    if(*stack_b == NULL || (*stack_b)->next == NULL || (*stack_b)->next->next == NULL)
        return;
    first = *stack_b;
    current = first;
    while (current->next !=NULL)
        current = current->next;
    last = current;
    *stack_b = first->next;
    last->next = first;
    first->next = NULL;
	ft_printf("rb\n");
}
void rr(t_stack **stack_a, t_stack **stack_b)
{
    ra(stack_a);
    rb(stack_b);
	ft_printf("rr\n");
}
void rra(t_stack **stack_a)
{
    t_stack *second_last;
    t_stack *last;
    if (*stack_a == NULL || (*stack_a)->next == NULL || (*stack_a)->next->next == NULL)
        return;
    second_last = *stack_a;
    while (second_last->next !=NULL && second_last->next->next !=NULL)
        second_last= second_last->next;
    last = second_last->next;
    second_last->next = NULL;
    last->next = *stack_a;
    *stack_a= last;
	ft_printf("rra\n");
}
void rrb(t_stack **stack_b)
{
    t_stack *second_last;
    t_stack *last;
    if (*stack_b == NULL || (*stack_b)->next == NULL || (*stack_b)->next->next == NULL)
        return;
    second_last = *stack_b;
    while (second_last->next !=NULL && second_last->next->next !=NULL)
        second_last= second_last->next;
    last = second_last->next;
    second_last->next = NULL;
    last->next = *stack_b;
    *stack_b = last;
	ft_printf("rrb\n");
}
void rrr(t_stack **stack_a, t_stack **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
	ft_printf("rrr\n");
}

void sb(t_stack **stack_b)
{
    t_stack *first;
    t_stack *second;

    first = *stack_b;
    second = first->next;

    first->next = second->next;
    second->next = first;

    *stack_b = second;
	ft_printf("sb\n");
}

void ss(t_stack **stack_a, t_stack **stack_b )
{
    sa(stack_a);
    sb(stack_b);
	ft_printf("ss\n");
}
void pa(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp; 
	
    if (*stack_b == NULL)
        return;
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = *stack_a; 
    *stack_a = tmp; 

    ft_printf("pa\n");
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;  
    if (*stack_a == NULL)
        return;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next; 
    tmp->next = *stack_b; 
    *stack_b = tmp;  

    ft_printf("pb\n");
}
