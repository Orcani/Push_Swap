/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: desambou <desambou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:03:35 by desambou          #+#    #+#             */
/*   Updated: 2024/12/15 12:59:28 by desambou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h> 
# include "../Libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"


// typedef struct s_stack
// {
//     int value;
// 	int index;
//     int push_cost;

// 	bool above_median;
// 	bool cheapest;

// 	struct s_stack *next;
// 	struct s_stack *target_node;
// } t_stack;

typedef struct s_stack
{
    int value;
    int current_position;
	int final_index;
    int push_cost;

	bool above_median;
	bool cheapest;

	struct s_stack *next;
    struct s_stack *prev;
	struct s_stack *target_node;
} t_stack;
// handle one argument ./push_swap "1 8 -42 1337"
char	**ft_split(char const *s, char c);

//handle errors-free
void error_check(t_stack *stack_a);
void free_result(char **result);
void free_stack(t_stack **stack_a);

// handle initialisation
int flag_ac_2(int ac);
int check_synthax(char *av);
int g_check(t_stack **stack_a, char **av /*, int flag_ac_2(int ac)*/);
int limits_check(long num);
int is_duplicate(t_stack *stack_a, int nb);

//handle creating stack
t_stack *create_cell_ps(long num);
void	ft_lstadd_back_ps(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast_ps(t_stack *lst);
void create_stack(t_stack **stack, int nb);

//the instructions
void sa(t_stack **stack_a);
void sb(t_stack **stack_b);
void ss(t_stack **stack_a, t_stack **stack_b );
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);
void ra(t_stack **stack_a);
void rb(t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);
void rra(t_stack **stack_a);
void rrb(t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack **stack_b);

//sorting
int stack_len(t_stack *stack_a);
int sorted(t_stack *stack);
t_stack *max(t_stack *stack_a);
t_stack *min(t_stack *stack_a);
void sorting_three(t_stack **stack_a);
void sort_stack(t_stack **stack_a, t_stack **stack_b);


// display to help me visualize
void printf_stack_a(t_stack **stack_a);
void printf_stack_b(t_stack **stack_b);
void printflist(t_stack *list);
void display( t_stack **stack_a);

#endif