/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverserotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:55:57 by ljylhank          #+#    #+#             */
/*   Updated: 2024/12/13 14:26:17 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack_node **node)
{
	t_stack_node	*first;
	t_stack_node	*last;

	if (!(*node) || !(*node)->next)
		return ;
	first = *node;
	last = *node;
	while (last->next)
		last = last->next;
	if (first->next == last)
		first->next = 0;
	if (last->prev)
		last->prev->next = 0;
	last->next = first;
	last->prev = 0;
	first->prev = last;
	*node = last;
	(*node)->prev = 0;
}

void	reverse_rotate_a(t_stack_node **a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_stack_node **b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_r(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
}
