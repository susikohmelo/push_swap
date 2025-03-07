/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_target.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:20:57 by ljylhank          #+#    #+#             */
/*   Updated: 2024/12/13 14:24:40 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	autorotate(t_stack_node **stack,
					t_stack_node *node, char which_stack)
{
	if (which_stack == 'a')
	{
		while (*stack != node)
		{
			if (node->above_median)
				rotate_a(stack);
			else
				reverse_rotate_a(stack);
		}
	}
	else
	{
		while (*stack != node)
		{
			if (node->above_median)
				rotate_b(stack);
			else
				reverse_rotate_b(stack);
		}
	}
}

static inline void	both_autorevrotate(t_stack_node **a, t_stack_node **b,
		t_stack_node *node)
{
	while (*a != node && *b != node->target)
		reverse_rotate_r(a, b);
	update_index_median_cheapest(*a);
	update_index_median_cheapest(*b);
}

static inline void	both_autorotate(t_stack_node **a, t_stack_node **b,
		t_stack_node *node)
{
	while (*a != node && *b != node->target)
		rotate_r(a, b);
	update_index_median_cheapest(*a);
	update_index_median_cheapest(*b);
}

void	push_to_b_target(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest_node(*a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		both_autorotate(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		both_autorevrotate(a, b, cheapest_node);
	autorotate(a, cheapest_node, 'a');
	autorotate(b, cheapest_node->target, 'b');
	push_b(a, b);
}

void	push_to_a_target(t_stack_node **a, t_stack_node **b)
{
	autorotate(a, (*b)->target, 'a');
	push_a(a, b);
}
