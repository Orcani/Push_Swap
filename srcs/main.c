/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:03:35 by desambou          #+#    #+#             */
/*   Updated: 2024/12/15 12:59:28 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(t_stack *stack_a)
{
    t_node *current;
    t_node *next_node;

    current = stack_a->top;
    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node; 
    }
    free(stack_a);
}

int main (int ac, char *av[])
{
    t_stack *stack_a;
    t_stack *stack_b;


    stack_a = NULL;
    stack_a = malloc(sizeof(t_stack));
    stack_b = NULL;
    stack_b = malloc(sizeof(t_stack));
    stack_a->top = NULL; 
    stack_b->top = NULL;
    stack_a = create_stack(ac, av);
    

    ft_printf("Input:\n");
    ft_printf("----------------------------------------\n");
  
    g_check(ac, av); // general check
    if (g_check(ac, av) == 1)
         return (ft_putstr_fd("Error\n", 2) , 1);
    ft_printf("_________________________________________\n");
    ft_printf("Instruction(s):\n");
    ft_printf("----------------------------------------\n");
    three(stack_a);
    // five_hundred(stack_a, stack_b);
    ft_printf("_________________________________________\n");
    ft_printf("Result Stack a:\n");
    ft_printf("----------------------------------------\n");
    printf_stack_a(stack_a);
    ft_printf("Result Stack b:\n");
    ft_printf("----------------------------------------\n");
    printf_stack_a(stack_b);

    t_node *current = stack_a->top;
    while (current)
    {
        t_node *tmp = current;
        current = current->next;
        free(tmp);
    }
    
    current = stack_b->top;
    while (current)
    {
        t_node *tmp = current;
        current = current->next;
        free(tmp);
    }
    // free_stack(stack_a);
    free(stack_a);
    free(stack_b);
    return (0);
}


// leaks for create_cell()
// still need to check the case with ./push_swap 98 99 02 "-9 28"
