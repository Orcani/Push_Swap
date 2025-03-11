/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:03:35 by desambou          #+#    #+#             */
/*   Updated: 2024/12/15 12:59:28 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int one_arg_first_check(char **av)
{
	int i;
    
    i = 0;
    while (av[1][i])
    {
        if (ft_isdigit(av[1][i]) || av[1][i] == 32 || av[1][i] == 9) 
            i++;
        else if (av[1][i] == '-' || av[1][i] == '+') 
        { 
            if (!ft_isdigit(av[1][i + 1])) 
                return (1);
            if ((i - 1) >= 0) 
            {
                if (av[1][i - 1] != 32 && av[1][i - 1] != 9 && !ft_isdigit(av[1][i - 1]))
                    return (1);
            }
            i++;
        }
        else
            return (1);
    }
    return (0);
}

int one_arg_second_check(char **av, t_stack **head)
{
    long num;
    int i;
    t_stack  *list;

    i = 0;
    list = NULL;
    if (one_arg_first_check(av) == 1)
        return(1);
    av = ft_split(av[1], ' ');
    if (!av) 
        return( 1);
    while (av[i] != NULL)
    {
        ft_printf("%s\n", av[i]);
        num = ft_atol(av[i]);
        if (limits_check(num) == 1)// && num != -2147483649 && num != -2147483648)//
             return(1);
        ft_lstadd_back_ps(&list, create_cell_ps(num));
        i++;
    }
    printflist(list);
    i = 0;
    while (av[i] != NULL)
    {
        free(av[i]);
        i++;   
    }      
    free(av);
    *head = list;
    return(0);
}

int error_synthax_char(char **av, int i_w, int i_c)
{
    if (!ft_isdigit(av[i_w][i_c + 1])) 
        return (1);
    if ((i_c - 1) >= 0) 
    {
        if (av[i_w][i_c - 1] != 32 && av[i_w][i_c - 1] != 9 && !ft_isdigit(av[i_w][i_c - 1]))
            return (1);
    }
    return(0);
}

int error_synthax(char **av)
{
    int i_c;
    int i_w;
     
    i_w = 1;
    while (av[i_w])
    {
        i_c = 0;
        while (av[i_w][i_c])
        {
            if (ft_isdigit(av[i_w][i_c]) || av[i_w][i_c] == 32 || av[i_w][i_c] == 9) 
                i_c++;
            else if (av[i_w][i_c] == '-' || av[i_w][i_c] == '+') 
            { 
                if (error_synthax_char(av, i_w, i_c) == 1)
                    return(1);
                i_c++;
            }
            else
                return (1);
        }
        i_w++;
    }
    return (0);
}

int mult_arg_second_check(char **av, t_stack **head)
{
    long num;
    int i;
    t_stack  *list;

    i = 1;
    list = NULL;
        if (mult_arg_first_check(av) == 1)
            return(1);
        while (av[i] != NULL) 
        {
            num = ft_atol(av[i]);
            if (limits_check(num) == 1)
                return(1);  
            ft_lstadd_back_ps(&list, create_cell_ps(num));
            i++;
        }
        printflist(list);
        *head = list;
    return (0);
}

int g_check(int ac, char *av[])
{
    long nombre;
    t_stack *head;

    nombre = 0; 
    head = NULL;
    if (ac == 1 || (ac == 2 && !av[1][0]))
        return (1);
    else if (ac == 2)
    { 
        if (one_arg_second_check(av, &head) == 1)
            return(1);
    }
    else if (ac > 2)
    {
        if (mult_arg_second_check(av, &head) == 1)
            return(1);
    }
    if (is_duplicate(head) == 1)
        return(1);
    return (0);
}
