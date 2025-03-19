/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:40:12 by desambou          #+#    #+#             */
/*   Updated: 2025/03/06 12:46:35 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*next;

	if (!stack_a) //Check for an empty stack
		return ;
	current = *stack_a;
	while (current)
	{
		next = current->next; 
		free(current); 
		current = next;  
	}
	*stack_a = NULL; 
}

void	free_result(char **result)
{
    int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]); 
		i++;
	}
	free(result);  
}

void	error_check(t_stack *stack_a)
{
	t_stack	*current;
	t_stack	*tmp;

	current = stack_a;
    while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
	ft_putstr_fd("Error\n", 2);
}
