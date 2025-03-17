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
    if (!stack) 
        return (1); // Empty stack is considered sorted

    while (stack->next)
    {
        if (stack->value > stack->next->value)
            return (0); // Found an unsorted pair
        stack = stack->next;
    }
    return (1); // Stack is sorted
}


void	current_index(t_stack_node *stack)
{
	int	i; //To store the index of the current node
	int	median; //To store the position of the median of the stack

	i = 0; //The first index is `0`
	if (!stack) //Check for am empty stack
		return ;
	median = stack_len(stack) / 2; //Calculate the median by dividing the length of a stack by 2
	while (stack) //Loop through all the nodes until the end of the stack is reached
	{
		stack->index = i; //Assign the current index value to the current node
		if (i <= median) //Check whether the current node is above or below the median
			stack->above_median = true; //If above, set the above_median data of the node to true
		else
			stack->above_median = false; //If below, set the above_median data of the node to false
		stack = stack->next; //Move to the next node for indexing
		++i; //Increment the index value to set the next node with
	}
}

static void	set_target_a(t_stack_node *a, t_stack_node *b)//Find `a` node's target in stack `b`
{
	t_stack_node	*current_b; //To store the pointer to the current node in stack `b` and iterate through each node following
	t_stack_node	*target_node; //To store the pointer to the target node in stack `b`
	long			best_match_index; //In this case, the best match indexe stores the value of the "closest smaller number" so far

	while (a) //As long as we have nodes in stack `a`
	{
		best_match_index = LONG_MIN; //Assign the smallest `long` as the closest smaller number so far
		current_b = b; //Assign to `current_b` the current `b` node
		while (current_b) //Iteratively search through all the nodes in stack `b` until the end of the stack is reached
		{
			if (current_b->nbr < a->nbr 
				&& current_b->nbr > best_match_index) //Check if `b` node is smaller than `a` node && bigger than the closest smaller number so far
			{
				best_match_index = current_b->nbr; //If so, update the value of the closest smaller number so far
				target_node = current_b; //Assign the current `b` node as the `target_node`
			}
			current_b = current_b->next; //Move to the next `b` node for comparison, until a "closer smaller number" is found
		}
		if (best_match_index == LONG_MIN) //Check if the LONG_MIN hasn't changed, it means we haven't found anything smaller
			a->target_node = find_max(b); //If so, find the biggest `nbr` and set this as the target node
		else
			a->target_node = target_node; //If no "closer smaller number" is found, and the best match has changed
		a = a->next; //Move to the next `a` node to find it's target `b` node
	}
}

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b) //Define a functio that analyses the cost of the `a` node along with it's target `b` node, which is the sum of the number of instructions for both the nodes to rotate to the top of their stacks
{
	int	len_a; //To store the length of stack `a`
	int	len_b; //To store the length of stack `b`

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a) //Loop through each node until the end of the stack is reached
	{
		a->push_cost = a->index; //Assign the current `a` node's push cost, its' index value
		if (!(a->above_median)) //Check if the above_median data is false, meaning it is below median
			a->push_cost = len_a - (a->index); //If so, update `a` node's push cost to the stack's length - index
		if (a->target_node->above_median) //Check if `a` node's target node `b` has a "true" above median attribute, meaning the target `b` node is above median
			a->push_cost += a->target_node->index; //If so, update `a` node's push cost, the sum of (its current index) + (its target `b` node's index)
		else //If `a` node is indeed above median and its target `b` node is below median
			a->push_cost += len_b - (a->target_node->index); //Update `a` node's push cost, the sum of (its current index) + (`b` stack's length - its target `b` node's index)
		a = a->next; //Move to the next `a` node for its cost analysis
	}
}

void	set_cheapest(t_stack_node *stack) //Define a function that sets a node's `cheapest` attribute as `true` or `false`
{
	long			cheapest_value; //To store the value of the cheapest node so far
	t_stack_node	*cheapest_node; //To store a pointer to the cheapest node so far

	if (!stack) //Check for an empty stack
		return ;
	cheapest_value = LONG_MAX; //Assign the biggest `long` as the cheapest value so far
	while (stack) //Loop through every node until the end of the stack is reached, and we find the cheapest node
	{
		if (stack->push_cost < cheapest_value) //Check if the current node's push cost is cheaper than the cheapest value so far
		{
			cheapest_value = stack->push_cost; //If so, update the cheapest value to the current node's push cost
			cheapest_node = stack; //Assign the current node as the cheapest node so far
		}
		stack = stack->next; //Move to the next node for comparison
	}
	cheapest_node->cheapest = true; //After iterating through the stack, if no cheaper node is found than the current, then set the cheapest node's `cheapest` attribut to `true` in the data structure
}

void	init_nodes_a(t_stack_node *a, t_stack_node *b) //Define a function that combines all the functions needed to prepare stack `a`, ready for our pushing and sorting. These functions set the data inside the node's structure
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
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


