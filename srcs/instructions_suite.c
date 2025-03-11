/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_suite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:55:20 by desambou          #+#    #+#             */
/*   Updated: 2025/03/02 19:47:21 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//instructions
void sa(t_stack *stack_a)
{
    t_stack *first;
    t_stack *second;


    first = stack_a->value;
    second = first->next;

    first->next = second->next;
    second->next = first;

    stack_a->value = second;
	ft_printf("sa\n");
}
void sb(t_stack *stack_b)
{
    t_stack *first;
    t_stack *second;

    first = stack_b->value;
    second = first->next;

    first->next = second->next;
    second->next = first;

    stack_b->value = second;
	ft_printf("sb\n");
}
void ss(t_stack *stack_a, t_stack *stack_b )
{
    sa(stack_a);
    sb(stack_b);
	ft_printf("ss\n");
}
void pa(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *tmp;  
    if (stack_b == NULL || stack_b->value == NULL)
        return;
    tmp = stack_b->value;
    stack_b->value = stack_b->value->next;
    
    tmp->next = stack_a->value;
    stack_a->value = tmp;
	ft_printf("pa\n");
}
void pb(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *tmp;  
    if (stack_a == NULL || stack_a->value == NULL)
        return;
    tmp = stack_a->value;
    stack_a->value = stack_a->value->next;
    
    tmp->next = stack_b->value;
    stack_b->value = tmp;
    ft_printf("pb\n");
}
void printf_stack_a(t_stack *stack_a)
{
    t_stack *temp;
    temp = stack_a->value;
    while (temp)
    {
        ft_printf("%d ", temp->value);
        temp = temp->next;
    }
    ft_printf("\n");
}