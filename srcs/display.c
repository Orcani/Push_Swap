/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:57:40 by desambou          #+#    #+#             */
/*   Updated: 2025/03/03 17:04:57 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printf_stack_a(t_stack **stack_a)
{
    t_stack *temp;
    temp = *stack_a;
    while (temp)
    {
        ft_printf("%d ", temp->value);
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
        ft_printf("%d ", temp->value);
        temp = temp->next;
    }
    ft_printf("\n");
}
void display( t_stack **stack_a, t_stack **stack_b)
{
	// ft_printf("_________________________________________\n");
    // ft_printf("Instruction(s):\n");
    // ft_printf("----------------------------------------\n");
   
    // five_hundred(stack_a, stack_b);
    ft_printf("_________________________________________\n");
    ft_printf("Result Stack a:\n");
    ft_printf("----------------------------------------\n");
    printf_stack_a(stack_a);
    ft_printf("Result Stack b:\n");
    ft_printf("----------------------------------------\n");
    printf_stack_a(stack_b);
}
 