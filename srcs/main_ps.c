/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:29:21 by desambou          #+#    #+#             */
/*   Updated: 2025/03/17 20:47:38 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// int stack_len(t_stack *stack_a)
// {
//     int i;
//     t_stack *temp;

//     i = 0;
//     temp = stack_a; 
//     while (temp)
//     {
//         temp = temp->next;  
//         i++; 
//     }
//     return (i);
// }

int main (int ac, char *av[])
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1); 
	else if (ac == 2)
    {
        av = ft_split(av[1], ' '); 
        if (g_check(&stack_a, av)) // problem de free avec substr
            {
                free_result(av);
                return(0);
            }
    } 
    else
    {
        if (g_check(&stack_a, av + 1))
            return (0);
    }
    if (!sorted(stack_a))
    { 
     ft_printf("not sorted\n");   //-> to delete later
        if (stack_len(stack_a) == 2)
            sa(&stack_a, false);
        else if (stack_len(stack_a) == 3)
            sort_three(&stack_a);
        else if (stack_len(stack_a) > 3)
            sort_stacks(&stack_a, &stack_b);
    }
    display(&stack_a); //-> to delete later
    display(&stack_b);
    if (ac == 2)
        free_result(av);
    free_stack(&stack_a);
    return (0);
}


//&stack_a to go to the memory address of the structure, av+1 is to skip the ./push_swap argument, boolan if it has two argements or not
