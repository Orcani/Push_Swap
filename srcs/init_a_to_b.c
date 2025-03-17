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

void	current_index(t_stack *stack)
{
	int	i; 
	int	median;
    
	i = 0; 
	if (!stack) 
		return ;
	median = stack_len(stack) / 2; 
	while (stack) 
	{
		stack->index = i; 
		if (i <= median) 
			stack->above_median = true; 
		else
			stack->above_median = false;
		stack = stack->next; 
		++i; 
	}
}

static void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b; 
	t_stack	*target_node; 
	long			best_match_index; 

	while (stack_a) 
	{
		best_match_index = LONG_MIN; 
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->nbr < stack_a->nbr && current_b->nbr > best_match_index) 
			{
				best_match_index = current_b->nbr; 
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN) 
			stack_a->target_node = max(stack_b);
		else
			stack_a->target_node = target_node; 
		stack_a = stack_a->next; 
	}
}

static void	cost_analysis_a(t_stack *stack_a, t_stack *stack_b) 
{
	int	len_a;
	int	len_b; 

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_a) 
	{
		stack_a->push_cost = stack_a->index; 
		if (!(stack_a->above_median)) 
			stack_a->push_cost = len_a - (stack_a->index); 
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index; 
		else 
			stack_a->push_cost += len_b - (stack_a->target_node->index); 
		stack_a = stack_a->next; 
	}
}

void	set_cheapest(t_stack *stack)
{
	long			cheapest_value;
	t_stack	*cheapest_node;

	if (!stack) 
		return ;
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
	cheapest_node->cheapest = true; 
}

void	init_nodes_a(t_stack *stack_a, t_stack *stack_b) 
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
/*
t_stack *min(t_stack *stack)
{
	long min;
	t_stack *min_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while(stack)
	{
		if(stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_stack *max(t_stack *stack)
{
	long max;
	t_stack *max_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while(stack)
	{
		if(stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
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
		stack->index = i;
		if(i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}
void rotate_both( t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
    while (*stack_b !=cheapest_node->target_node && *stack_a != cheapest_node)
        rr(stack_a, stack_b);
    current_pos(*stack_a),
    current_pos(*stack_b);
}
void rev_rotate_both( t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_node)
{
    while (*stack_b !=cheapest_node->target_node && *stack_a != cheapest_node)
        rrr(stack_a, stack_b);
    current_pos(*stack_a),
    current_pos(*stack_b);
}

void set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *current_b;
	t_stack *target_node;
    long best_match_i;
    // target_node = NULL;
	while(stack_a)
	{
		best_match_i = LONG_MIN;
		current_b = stack_b;
		while(current_b)
		{
			if(current_b->value < stack_a->value
                && current_b->value > best_match_i)
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

static void cost_analysis_a(t_stack *stack_a, t_stack *stack_b)
{
	int len_a;
	int len_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a-> above_median))
			stack_a->push_cost = len_a -(stack_a->index);
		if(stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += len_b - (stack_a->target_node->index);
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
    if (cheapest_node) 
        cheapest_node->cheapest = true;
}

void prep_for_push(t_stack **stack, t_stack *top_node, char *stack_name)
{
    while (*stack != top_node)
    {
        if(ft_strncmp(stack_name, "stack_a", 7) == 0)
        {
            if (top_node->above_median)
                ra(stack);
            else
                rra(stack);
        }
        else if (ft_strncmp(stack_name, "stack_b", 7) == 0)
        {
            if (top_node->above_median)
                rb(stack);
            else    
                rrb(stack);
        }
    }
}


static void set_target_b(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *current_a;
    t_stack *target_node;
    long best_match_i;
    
    while (stack_b)
    {
        best_match_i = LONG_MAX;
        current_a = stack_a;
        while(current_a)
        {
            if (current_a->value > stack_b->value
                && current_a->value < best_match_i)
            {
                best_match_i = current_a->value;
                target_node = current_a;
            }
            current_a = current_a->next;
        }
        if (best_match_i == LONG_MAX)
            stack_b->target_node = min(stack_a);
        else
            stack_b->target_node = target_node;
        stack_b = stack_b->next;
    }
}
static void a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheapest_node;

	cheapest_node = get_cheapest(*stack_a);
	if(cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
    else if (!(cheapest_node->above_median)
        && !(cheapest_node->target_node->above_median))
        rev_rotate_both(stack_a, stack_b, cheapest_node);
    prep_for_push(stack_a, cheapest_node, "stack_a");
    prep_for_push(stack_b, cheapest_node->target_node, "stack_b");
    pb(stack_a, stack_b);
}

static void b_to_a(t_stack **stack_a, t_stack **stack_b)
{
    prep_for_push(stack_a, (*stack_b)->target_node, "stack_a");
    pa(stack_a, stack_b);
}

static void min_on_top(t_stack **stack_a)
{
    while ((*stack_a)->value != min(*stack_a)->value)
    {
        if (min(*stack_a)->above_median)
            ra(stack_a);
        else
            rra(stack_a);
    }
}

void init_b(t_stack *stack_a, t_stack *stack_b)
{
    current_pos(stack_a);
    current_pos(stack_b);
    set_target_b(stack_a, stack_b);
}

void init_a(t_stack *stack_a, t_stack *stack_b)
{
	current_pos(stack_a);
	current_pos(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}
void sort_stack(t_stack **stack_a, t_stack **stack_b)
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
		init_b(*stack_a, *stack_b);
		b_to_a(stack_a, stack_b);
	}
	current_pos(*stack_a);
	min_on_top(stack_a);
}
*/



// pivot tri quatrieme se place haut, bas, mileu dependant de sa valeur


