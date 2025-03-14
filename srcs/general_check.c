/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:46:20 by desambou          #+#    #+#             */
/*   Updated: 2025/03/06 12:41:17 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int flag_ac_2(int ac)
{
	if (ac == 2)
		return(1);
	return (0);
}

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
        if (stack_a->value == nb)
            return (1);
        stack_a = stack_a->next;
    }
    return(0);
}

// stop the program when an error comes


// create_stack
void create_stack(t_stack **stack, int nb)
{
	t_stack *top;
	t_stack *bottom;
	
	if (!stack)
		return;
	top = malloc(sizeof(t_stack));
	if (!top)
		return;
	top->value = nb;
    top->index= 0;
    top->target_node = NULL;	
	top->next = NULL;
	
	if (!*stack)
	{
		*stack = top;
	}
	else
	{
		bottom = ft_lstlast_ps(*stack);
		bottom->next = top;
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
void printflist(t_stack *list) //-> to delete later
{
    t_stack *temp;
    temp = list;
    while (temp)
    {
        ft_printf("%d ", (int)temp->value);
        temp = temp->next;
    }
    ft_printf("\n");
}
// general function to check all the criterias for multiple av (after the split)
int g_check(t_stack **stack_a, char **av /*, int flag_ac_2(int ac)*/)
{
    long nb;
	int i;

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
		create_stack(stack_a, (int)nb);
		i++;
	}
	ft_printf("Input:\n");//-> to delete later
	printflist(*stack_a); //-> to delete later
    return (0);
}


