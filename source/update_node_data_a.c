/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_node_data_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:23:23 by ljylhank          #+#    #+#             */
/*   Updated: 2024/12/13 14:23:25 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_index_median_cheapest(t_stack_node *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = get_stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		stack->cheapest = false;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static inline void	update_targets_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cur_node;
	t_stack_node	*target;
	long			closest_match;

	while (a)
	{
		closest_match = LONG_MIN;
		cur_node = b;
		while (cur_node)
		{
			if (a->val > cur_node->val && cur_node->val > closest_match)
			{
				target = cur_node;
				closest_match = cur_node->val;
			}
			cur_node = cur_node->next;
		}
		if (closest_match == LONG_MIN)
			target = get_biggest_node(b);
		a->target = target;
		a = a->next;
	}
}

static inline void	update_cost_a(t_stack_node *a, t_stack_node *b)
{
	int	a_len;
	int	b_len;

	a_len = get_stack_len(a);
	b_len = get_stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = a_len - (a->index);
		if (!(a->target->above_median))
			a->push_cost += b_len - (a->target->index);
		else
			a->push_cost += (a->target->index);
		a = a->next;
	}
}

static inline void	update_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest_node;
	int				cheapest_cost;

	if (!stack)
		return ;
	cheapest_cost = INT_MAX;
	while (stack)
	{
		if (stack->push_cost <= cheapest_cost)
		{
			cheapest_node = stack;
			cheapest_cost = stack->push_cost;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	update_node_data_a(t_stack_node *a, t_stack_node *b)
{
	update_index_median_cheapest(a);
	update_index_median_cheapest(b);
	update_targets_a(a, b);
	update_cost_a(a, b);
	update_cheapest(a);
}
