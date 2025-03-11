/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:57:51 by desambou          #+#    #+#             */
/*   Updated: 2025/03/01 19:21:19 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// algo for three numbers
void three(t_stack *stack_a)
{
 	if (stack_a == NULL || stack_a->top == NULL || stack_a->top->next == NULL || stack_a->top->next->next == NULL)
        return; 
	
	t_node *first;
    t_node *second;
	t_node *third;
    
	first = stack_a->top;
    second = first->next;
	third = second->next;
	if (first->num < second->num && second->num < third->num)
		return;
    if (first->num > second->num && second->num > third->num)
    {
        sa(stack_a); 
        rra(stack_a);
    }
    else if (first->num > second->num && second->num < third->num && first->num < third->num)
	{
		sa(stack_a);   
	}
	else if (first->num > second->num && second->num < third->num && first->num > third->num)
	{
		ra(stack_a);
	}
    else if (first->num < second->num && second->num > third->num && first->num > third->num)
	{
		rra(stack_a);
	}
	else if (first->num < second->num && second->num > third->num && first->num < third->num)
    {
		sa(stack_a);
        ra(stack_a);
    }
}


// void five_hundred(t_stack *stack_a,  t_stack *stack_b)
// {
// 	if (stack_a == NULL || stack_a->top == NULL || stack_a->top->next == NULL || stack_a->top->next->next == NULL)
//         return;
	
// 	t_node *first;
//     t_node *second;
// 	t_node *third;
// 	t_node *fourth;
// 	t_node *fifth;
	
// 	first = stack_a->top;
//     second = first->next;
// 	third = second->next;
// 	fourth = third->next;
// 	fifth = fourth->next;
// 	if (first->num < second->num && second->num < third->num && third->num < fourth->num && fourth->num < fifth->num)
// 		return;
// 	pb

	
// }
	



// algo for one hundred numbers

// algo for five hundred numbers