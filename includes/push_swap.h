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


typedef struct s_stack 
{
	int					nbr; 
	int					index; 
	int					push_cost;
	bool				above_median; 
	bool				cheapest; 
	struct s_stack	*target_node;
	struct s_stack	*next; 
	struct s_stack	*prev; 
}	t_stack;

// handle one argument ./push_swap "1 8 -42 1337"
char	**ft_split(char const *s, char c);

//handle errors-free
void error_check(t_stack *stack_a);
void free_result(char **result);
void free_stack(t_stack **stack_a);

// handle initialisation
int check_synthax(char *av);
int g_check(t_stack **stack_a, char **av);
int limits_check(long num);
int is_duplicate(t_stack *stack_a, int nb);


//***Nodes initiation
void			init_nodes_a(t_stack *stack_a, t_stack *stack_b); 
void			init_nodes_b(t_stack *stack_a, t_stack *stack_b); 
void			current_index(t_stack *stack); 
void			set_cheapest(t_stack *stack); 
t_stack         *get_cheapest(t_stack *stack); 
void			prep_for_push(t_stack **s, t_stack *n, char *c);

//handle creating stack
void	ft_lstadd_back_ps(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast_ps(t_stack *lst);
t_stack *new_node_ps(int nb);
void create_stack(t_stack **stack, t_stack *new_node);

//***Commands
void			sa(t_stack **stack_a, bool print);
void			sb(t_stack **stack_b, bool print);
void			ss(t_stack **stack_a, t_stack **stack_b, bool print);
void			ra(t_stack **stack_a, bool print);
void			rb(t_stack **stack_b, bool print);
void			rr(t_stack **stack_a, t_stack **stack_b, bool print);
void			rra(t_stack **stack_a, bool print);
void			rrb(t_stack **stack_b, bool print);
void			rrr(t_stack **stack_a, t_stack **stack_b, bool print);
void			pa(t_stack **stack_a, t_stack **stack_b, bool print);
void			pb(t_stack **stack_b, t_stack **stack_a, bool print);

//***Algorithm
void			sort_three(t_stack **stack_a /*, t_stack **stack_b*/);
void			sort_stacks(t_stack **stack_a, t_stack **stack_b); 

//sorting
// int stack_len(t_stack *stack_a);
// int sorted(t_stack *stack);
t_stack *max(t_stack *stack);
t_stack *min(t_stack *stack);
int				stack_len(t_stack *stack); 
t_stack	*find_last(t_stack *stack); 
bool    sorted(t_stack *stack); 
 


// display to help me visualize
void printf_stack_a(t_stack **stack_a);
void printf_stack_b(t_stack **stack_b);
void printflist(t_stack *list);
void display( t_stack **stack_a);
void tmp_display(t_stack **stack_a, t_stack **stack_b);

#endif