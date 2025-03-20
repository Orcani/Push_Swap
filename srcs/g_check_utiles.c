/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_check_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:49:07 by desambou          #+#    #+#             */
/*   Updated: 2025/03/20 12:49:25 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node_ps(int nb)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->nbr = nb;
	new_node->index = 0;
	new_node->target_node = NULL;
	new_node->push_cost = 0;
	new_node->above_median = false;
	new_node->cheapest = false;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

// create_stack
void	create_stack(t_stack **stack, t_stack *new_node)
{
	t_stack	*bottom;

	if (!*stack)
		*stack = new_node;
	else
	{
		bottom = ft_lstlast_ps(*stack);
		bottom->next = new_node;
		new_node->prev = bottom;
	}
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
