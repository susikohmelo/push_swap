/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:21:44 by ljylhank          #+#    #+#             */
/*   Updated: 2024/12/13 14:21:45 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **stack)
{
	t_stack_node	*biggest;

	biggest = get_biggest_node(*stack);
	if (*stack == biggest)
		rotate_a(stack);
	else if ((*stack)->next == biggest)
		reverse_rotate_a(stack);
	if ((*stack)->val > (*stack)->next->val)
		swap_a(stack);
}

static inline void	rotate_smallest_to_top(t_stack_node **stack)
{
	t_stack_node	*smallest_node;

	smallest_node = get_smallest_node(*stack);
	while (*stack != smallest_node)
	{
		if (smallest_node->above_median)
			rotate_a(stack);
		else
			reverse_rotate_a(stack);
	}
}

void	sort_all(t_stack_node **a, t_stack_node **b)
{
	int	a_len;

	a_len = get_stack_len(*a);
	if (a_len-- > 3 && !is_stack_sorted(*a))
		push_b(a, b);
	if (a_len-- > 3 && !is_stack_sorted(*a))
		push_b(a, b);
	while (a_len-- > 3 && !is_stack_sorted(*a))
	{
		update_node_data_a(*a, *b);
		push_to_b_target(a, b);
	}
	sort_three(a);
	while (*b)
	{
		update_node_data_b(*a, *b);
		push_to_a_target(a, b);
	}
	update_index_median_cheapest(*a);
	rotate_smallest_to_top(a);
}
