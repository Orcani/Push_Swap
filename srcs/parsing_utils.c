/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:16:52 by desambou          #+#    #+#             */
/*   Updated: 2025/03/02 19:12:23 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack	*ft_lstlast_ps(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast_ps(*lst);
	last->next = new;
}


void printflist(t_stack *list)
{
    t_stack *temp;
    temp = list;
    while (temp)
    {
        ft_printf("%d ", (int)temp->nbr);
        temp = temp->next;
    }
    ft_printf("\n");
}


int is_duplicate(t_stack *head)
{
    t_stack *current = head;
    t_stack *after;
    while (current)
    {
        after = current->next;
        while (after)
        {
            if (current->num == after->num)
                return (1);
            after = after->next;
        }
        current = current->next;
    }
    return(0);
}
// leaks here
t_stack *create_cell_ps(long nb)
{
    t_stack *cell;

    cell = malloc(sizeof(t_stack)); //malloc donc free autre part;
    if (!cell)
        return(NULL);
    cell->nbr = nb;
    cell->next = NULL;
    return (cell);
}

t_stack *create_stack(int argc, char **argv)
{
    t_stack *stack = malloc(sizeof(t_stack)); 
    int i = 1;
    if (!stack)
        return NULL;
    stack->top = NULL;   
    while(i < argc)
    {
        long num = atol(argv[i]);  
        t_stack *new_node = create_cell_ps(num);  
        ft_lstadd_back_ps(&stack->top, new_node);  
        i++;
    }
    return stack;  
}


int limits_check(long num)
{
    if (num < INT_MIN || num > INT_MAX)
        return 1;
    if (num == -2147483649)
        return (ft_printf("-2147483648\n"), 0);
    if (num == 2147483648)
        return (ft_printf("-2147483648\n"), 0);
    return 0;
}