/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:53:47 by desambou          #+#    #+#             */
/*   Updated: 2025/03/01 17:50:40 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//instructions
void ra(t_stack *stack_a)
{
    t_node *first;
    t_node *last;
    t_node *current;

    if(stack_a == NULL || stack_a->top == NULL || stack_a->top->next == NULL)
        return;
    first = stack_a->top;
    current = stack_a->top;
    while (current->next !=NULL)
        current = current->next;
    last = current;
    stack_a->top= first->next;
    last->next = first;
    first->next = NULL;
	ft_printf("ra\n");
}
void rb(t_stack *stack_b)
{
    t_node *first;
    t_node *last;
    t_node *current;

    if(stack_b == NULL || stack_b->top == NULL || stack_b->top->next == NULL)
        return;
    first = stack_b->top;
    current = stack_b->top;
    while (current->next !=NULL)
        current = current->next;
    last = current;
    stack_b->top= first->next;
    last->next = first;
    first->next = NULL;
	ft_printf("rb\n");
}
void rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
	ft_printf("rr\n");
}
void rra(t_stack *stack_a)
{
    t_node *second_last;
    t_node *last;
    if (stack_a == NULL || stack_a->top == NULL || stack_a->top->next == NULL)
        return;
    second_last = stack_a->top;
    while (second_last->next !=NULL && second_last->next->next !=NULL)
        second_last= second_last->next;
    last = second_last->next;
    second_last->next = NULL;
    last->next = stack_a->top;
    stack_a->top = last;
	ft_printf("rra\n");
}
void rrb(t_stack *stack_b)
{
    t_node *second_last;
    t_node *last;
    if (stack_b == NULL || stack_b->top == NULL || stack_b->top->next == NULL)
        return;
    second_last = stack_b->top;
    while (second_last->next !=NULL && second_last->next->next !=NULL)
        second_last= second_last->next;
    last = second_last->next;
    second_last->next = NULL;
    last->next = stack_b->top;
    stack_b->top = last;
	ft_printf("rrb\n");
}
void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
	ft_printf("rrr\n");
}