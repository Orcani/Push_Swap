/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:46:20 by desambou          #+#    #+#             */
/*   Updated: 2025/03/19 19:11:39 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_synthax(char *av)
{
    int i_c;

        i_c = 0;
        while (av[i_c])
        {
            if (ft_isdigit(av[i_c]) || av[i_c] == 32 || av[i_c] == 9) 
                i_c++;
            else if (av[i_c] == '-' || av[i_c] == '+') 
            { 
                    if (!ft_isdigit(av[i_c + 1])) 
						return (1);
					if (i_c > 0 && (ft_isdigit(av[i_c - 1]) || av[i_c - 1] == '-' || av[i_c - 1] == '+'))
						return (1);
                i_c++;
            }
            else
                return (1);
        }
    return (0);
}

// check the duplicate

int is_duplicate(t_stack *stack_a, int nb)
{
	if (!stack_a)
		return (0);
    while (stack_a)
    {
        if (stack_a->nbr == nb)
            return (1);
        stack_a = stack_a->next;
    }
    return(0);
}

t_stack *new_node_ps(int nb)
{
    t_stack *new_node;
    new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return NULL;
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
void create_stack(t_stack **stack, t_stack *new_node)
{
	t_stack *bottom;
	
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


// void printflist(t_stack *list) //-> to delete later
// {
//     t_stack *temp;
//     temp = list;
//     while (temp)
//     {
//         ft_printf("%d ", (int)temp->nbr);
//         temp = temp->next;
//     }
//     ft_printf("\n");
// }
// general function to check all the criterias for multiple av (after the split)
int g_check(t_stack **stack_a, char **av)
{
    long nb;
	int i;
    t_stack *new_node;
	i = 0;
	while(av[i])
    {
        
		if (check_synthax(av[i]))
			return(error_check(*stack_a), 1);
		nb = ft_atol(av[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return(error_check(*stack_a), 1);
		if (is_duplicate(*stack_a, (int)nb))
			return(error_check(*stack_a), 1);
        new_node = new_node_ps(nb);
		create_stack(stack_a, new_node);
		i++;
	}
    return (0);
}


