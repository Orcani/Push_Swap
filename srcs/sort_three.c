/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:19:43 by desambou          #+#    #+#             */
/*   Updated: 2025/03/20 13:27:40 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	t_stack	*biggest_node;

	biggest_node = max(*stack_a);
	if (biggest_node == *stack_a)
		ra(stack_a, false);
	else if ((*stack_a)->next == biggest_node)
		rra(stack_a, false);
	if ((*stack_a)->nbr > (*stack_a)->next->nbr)
		sa(stack_a, false);
}

void	sort_stacks(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !sorted(*stack_a))
		pb(stack_b, stack_a, false);
	if (len_a-- > 3 && !sorted(*stack_a))
		pb(stack_b, stack_a, false);
	while (len_a-- > 3 && !sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	min_on_top(stack_a);
}
