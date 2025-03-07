/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_node_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:21:21 by ljylhank          #+#    #+#             */
/*   Updated: 2024/12/13 14:30:06 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*get_last_node(t_stack_node *stack)
{
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

t_stack_node	*get_biggest_node(t_stack_node *stack)
{
	t_stack_node	*biggest;

	biggest = stack;
	while (stack)
	{
		if (stack->val > biggest->val)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

t_stack_node	*get_smallest_node(t_stack_node *stack)
{
	t_stack_node	*smallest;

	smallest = stack;
	while (stack)
	{
		if (stack->val < smallest->val)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

t_stack_node	*get_cheapest_node(t_stack_node *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (0);
}

int	get_stack_len(t_stack_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
