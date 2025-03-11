/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:22:22 by desambou          #+#    #+#             */
/*   Updated: 2025/03/06 21:59:00 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int sorted(t_stack *stack)
{
    if (!stack || !stack->next) 
        return (1);
    
    while (stack->next)
    {
        if (stack->value > stack->next->value)  
            return (0);
        stack = stack->next;
    }
    return (1);  
}


void sorting_three(t_stack **stack_a)
{
t_stack *biggest_node;

biggest_node = max(*stack_a);
if(biggest_node == *stack_a)
	ra(stack_a);
else if ((*stack_a)->next == biggest_node)
	rra(stack_a);
if ((*stack_a)->value > (*stack_a)->next->value)
	sa(stack_a);
}
t_stack *max(t_stack *stack_a)
{
	long max;
	t_stack *max_node;

	if (!stack_a)
		return (NULL);
	max = LONG_MIN;
	while(stack_a)
	{
		if(stack_a->value > max)
		{
			max = stack_a->value;
			max_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (max_node);
}

t_stack *min(t_stack *stack_a)
{
	long min;
	t_stack *min_node;

	if (!stack_a)
		return (NULL);
	min = LONG_MAX;
	while(stack_a)
	{
		if(stack_a->value < min)
		{
			min = stack_a->value;
			min_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (min_node);
}
   
// void push_swap(t_stack **stack_a,  t_stack **stack_b)
// {
//     int len = stack_len(stack_a);
//     int count = 0;
//     while (count < len)
//     {
//         if(*stack_a != min || *stack_a != max)
// 			{
				
// 			}
// 			count++;
//     }
// }
static void cost_analysis_a(t_stack *stack_a, t_stack *stack_b)
{
	int len_a;
	int len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->final_i;
		if (!(stack_a-> above_median))
			stack_a->push_cost = len_a -(stack_a->final_i);
		if(stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->final_i;
		else
			stack_a->push_cost += len_b - (stack_a->target_node->final_i);
		stack_a = stack_a->next;
	}
}

void set_cheapest(t_stack *stack)
{
	long cheapest_value;
	t_stack *cheapest_node;

	if (!stack)
		return;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
	
}
void init_a(t_stack *stack_a, t_stack *stack_b)
{
	current_pos(stack_a);
	current_pos(stack_b);
	set_targer_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
void current_pos(t_stack *stack)
{
	int i;
	int median;
	i = 0;
	if(!stack)
		return;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->final_i = i;
		if(i <= median)
			stack->above_median = 1;
		if(i <= median)
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}
int set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *current_b;
	t_stack *target_node;
	long best_match_i;
	while(stack_a)
	{
		best_match_i = LONG_MIN;
		current_b = stack_b;
		while(current_b)
		{
			if(current_b->value < stack_a->value && current_b->value > best_match_i)
				{
					best_match_i = current_b->value;
					target_node = current_b;
				}
			current_b = current_b->next;
		}
		if(best_match_i == LONG_MIN)
			stack_a->target_node = max(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}	
}
static void a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheapest_node;
	cheapest_node = get_cheapest(*stack_a);
	if(cheapest_node->above_median && cheapest_node->target_node->above_median)
		r
}
int sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int len_stack_a;
	len_stack_a = stack_len(*stack_a);
	if (len_stack_a-- > 3 && !sorted(*stack_a))
		pb(stack_b, stack_a);
	if (len_stack_a-- > 3 && !sorted(*stack_a))
		pb(stack_b, stack_a);
	while(len_stack_a-- > 3 && !sorted(*stack_a))
	{
		init_a(*stack_a, *stack_b);
		a_to_b(stack_a, stack_b);
	}
	sorting_three(stack_a);
	while (*stack_b)
	{
		init_a(*stack_a, *stack_b);
		b_to_a(stack_a, stack_b);
	}
	current_ps(*stack_a);
	min_tp_top(stack_a)
}


// pivot tri quatrieme se place haut, bas, mileu dependant de sa valeur


