/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_node_data_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:22:54 by ljylhank          #+#    #+#             */
/*   Updated: 2024/12/13 14:22:57 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	update_targets_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*cur_node;
	t_stack_node	*target;
	long			closest_match;

	while (b)
	{
		closest_match = LONG_MAX;
		cur_node = a;
		while (cur_node)
		{
			if (b->val < cur_node->val && cur_node->val < closest_match)
			{
				target = cur_node;
				closest_match = cur_node->val;
			}
			cur_node = cur_node->next;
		}
		if (closest_match == LONG_MAX)
			target = get_smallest_node(a);
		b->target = target;
		b = b->next;
	}
}

void	update_node_data_b(t_stack_node *a, t_stack_node *b)
{
	update_index_median_cheapest(a);
	update_index_median_cheapest(b);
	update_targets_b(a, b);
}
