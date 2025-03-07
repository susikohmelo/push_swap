/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:55:57 by ljylhank          #+#    #+#             */
/*   Updated: 2024/12/13 14:25:03 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	swap(t_stack_node **node)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (!(*node) || !((*node)->next))
		return ;
	first = *node;
	second = (*node)->next;
	if (second->next)
		second->next->prev = first;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = 0;
	*node = second;
}

void	swap_a(t_stack_node **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stack_node **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	swap_s(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
