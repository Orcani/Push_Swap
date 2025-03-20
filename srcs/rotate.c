/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:19:26 by desambou          #+#    #+#             */
/*   Updated: 2025/03/20 13:01:57 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **stack_a, bool print)
{
	rotate(stack_a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack **stack_b, bool print)
{
	rotate(stack_b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, bool print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!print)
		ft_printf("rr\n");
}
