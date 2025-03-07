/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_stack_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:21:27 by ljylhank          #+#    #+#             */
/*   Updated: 2024/12/13 14:31:07 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline bool	errors_found(t_stack_node **a, char **argv, int free_argv)
{
	if (*a)
		free_stack(*a);
	if (free_argv == -1)
		free_str_array(argv);
	return (false);
}

static inline int	stack_atoi(char *str, bool *error)
{
	long	rval;
	int		sign;

	*error = true;
	if (!str[0])
		return (0);
	sign = 1;
	if (str[0] == '-')
	{
		str++;
		sign = -1;
	}
	rval = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		if ((rval * 10 + *str - '0') * sign > INT_MAX
			|| (rval * 10 + *str - '0') * sign < INT_MIN)
			return (0);
		rval = rval * 10 + *str - '0';
		str++;
	}
	*error = false;
	return ((int)(rval * sign));
}

bool	has_duplicates(t_stack_node *stack)
{
	t_stack_node	*stack_cpy;

	while (stack)
	{
		stack_cpy = stack->next;
		while (stack_cpy)
		{
			if (stack_cpy->val == stack->val)
				return (true);
			stack_cpy = stack_cpy->next;
		}
		stack = stack->next;
	}
	return (false);
}

static inline void	append_and_initialize(t_stack_node **a, t_stack_node *new)
{
	t_stack_node	*last_node;

	if (!(*a))
	{
		*a = new;
		new->prev = 0;
	}
	else
	{
		last_node = get_last_node(*a);
		last_node->next = new;
		new->prev = last_node;
	}
	new->cheapest = false;
	new->next = 0;
}

bool	assign_stack_values(t_stack_node **a, char **argv, int argv_is_heap)
{
	t_stack_node	*new_node;
	bool			error;
	int				n;
	int				i;

	i = 0;
	while (argv[i])
	{
		n = stack_atoi(argv[i], &error);
		if (error || (argv[i][0] == '0' && ft_isdigit(argv[i][1])))
			return (errors_found(a, argv, argv_is_heap));
		new_node = malloc(sizeof(t_stack_node));
		if (!new_node)
			return (errors_found(a, argv, argv_is_heap));
		new_node->val = n;
		append_and_initialize(a, new_node);
		if (has_duplicates(*a))
			return (errors_found(a, argv, argv_is_heap));
		i++;
	}
	return (true);
}
