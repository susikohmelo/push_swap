/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:49:40 by ljylhank          #+#    #+#             */
/*   Updated: 2024/12/13 15:00:43 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_node
{
	int					val;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

void			push_a(t_stack_node **a, t_stack_node **b);
void			push_b(t_stack_node **a, t_stack_node **b);

void			swap_a(t_stack_node **a);
void			swap_b(t_stack_node **b);
void			swap_s(t_stack_node **a, t_stack_node **b);

void			rotate_a(t_stack_node **a);
void			rotate_b(t_stack_node **b);
void			rotate_r(t_stack_node **a, t_stack_node **b);

void			reverse_rotate_a(t_stack_node **a);
void			reverse_rotate_b(t_stack_node **b);
void			reverse_rotate_r(t_stack_node **a, t_stack_node **b);

int				get_stack_len(t_stack_node *stack);
bool			is_stack_sorted(t_stack_node *a);
t_stack_node	*get_biggest_node(t_stack_node *stack);
t_stack_node	*get_smallest_node(t_stack_node *stack);
t_stack_node	*get_cheapest_node(t_stack_node *stack);
t_stack_node	*get_last_node(t_stack_node *stack);

void			free_stack(t_stack_node	*stack);
void			free_str_array(char	**str_array);

bool			assign_stack_values(t_stack_node **a, char **argv,
					int argv_is_heap);

void			push_to_b_target(t_stack_node **a, t_stack_node **b);
void			push_to_a_target(t_stack_node **a, t_stack_node **b);

void			update_index_median_cheapest(t_stack_node *stack);
void			sort_three(t_stack_node **stack);
void			sort_all(t_stack_node **a, t_stack_node **b);
void			update_node_data_a(t_stack_node *a, t_stack_node *b);
void			update_node_data_b(t_stack_node *a, t_stack_node *b);

#endif
