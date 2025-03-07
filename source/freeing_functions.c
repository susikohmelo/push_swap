/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:21:24 by ljylhank          #+#    #+#             */
/*   Updated: 2024/12/13 15:00:36 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_str_array(char	**str_array)
{
	int		i;

	if (!str_array)
		return ;
	i = 0;
	while (str_array[i])
	{
		free(str_array[i]);
		i++;
	}
	free(str_array[i]);
	free(str_array);
}

void	free_stack(t_stack_node	*stack)
{
	t_stack_node	*next;

	if (!stack)
		return ;
	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}
