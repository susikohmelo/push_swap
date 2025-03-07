/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:55:57 by ljylhank          #+#    #+#             */
/*   Updated: 2024/12/13 14:25:45 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	rotate(t_stack_node **node)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!(*node)->next)
		return ;
	first = *node;
	last = *node;
	while (last->next)
		last = last->next;
	*node = first->next;
	last->next = first;
	first->prev = last;
	first->next = 0;
	(*node)->prev = 0;
}

void	rotate_a(t_stack_node **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack_node **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_r(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}
