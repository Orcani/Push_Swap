/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:57:40 by desambou          #+#    #+#             */
/*   Updated: 2025/03/17 21:29:01 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printf_stack_a(t_stack **stack_a)
{
    t_stack *temp;
    temp = *stack_a;
    while (temp)
    {
        ft_printf("%d ", temp->nbr);
        temp = temp->next;
    }
    ft_printf("\n");
}
void printf_stack_b(t_stack **stack_b)
{
    t_stack *temp;
    temp = *stack_b;
    while (temp)
    {
        ft_printf("%d ", temp->nbr);
        temp = temp->next;
    }
    ft_printf("\n");
}
void display(t_stack **stack_a)
{
    printf_stack_a(stack_a);
}

void tmp_display(t_stack **stack_a, t_stack **stack_b)
{
    printf("\nstack a\n");
    printf_stack_a(stack_a);
    printf("\nstack b\n");
    printf_stack_b(stack_b);
}
