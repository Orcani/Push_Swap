/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:46:20 by desambou          #+#    #+#             */
/*   Updated: 2025/03/20 14:05:02 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_synthax(char	*av)
{
	int	i_c;

	i_c = 0;
	while (av[i_c])
	{
		if (ft_isdigit(av[i_c]) || av[i_c] == 32 || av[i_c] == 9)
			i_c++;
		else if (av[i_c] == '-' || av[i_c] == '+')
		{
			if (!ft_isdigit(av[i_c + 1]))
				return (1);
			if (i_c > 0 && (ft_isdigit(av[i_c - 1])
					|| av[i_c - 1] == '-' || av[i_c - 1] == '+'))
				return (1);
			i_c++;
		}
		else
			return (1);
	}
	return (0);
}

// check the duplicate
int	is_duplicate(t_stack *stack_a, int nb)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->nbr == nb)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

// general function to check all the criterias for multiple av (after the split)
int	g_check(t_stack **stack_a, char **av)
{
	long	nb;
	int		i;
	t_stack	*new_node;

	i = 0;
	while (av[i])
	{
		if (check_synthax(av[i]))
			return (error_check(*stack_a), 1);
		nb = ft_atol(av[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (error_check(*stack_a), 1);
		if (is_duplicate(*stack_a, (int)nb))
			return (error_check(*stack_a), 1);
		new_node = new_node_ps(nb);
		create_stack(stack_a, new_node);
		i++;
	}
	return (0);
}
