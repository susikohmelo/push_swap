/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:55:57 by ljylhank          #+#    #+#             */
/*   Updated: 2024/12/13 14:27:13 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	push(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp;

	if (!(*b))
		return ;
	temp = *a;
	*a = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = 0;
	(*a)->next = temp;
	if ((*a)->next)
		(*a)->next->prev = *a;
	(*a)->prev = 0;
}

void	push_a(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}
