/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljylhank <ljylhank@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:21:10 by ljylhank          #+#    #+#             */
/*   Updated: 2024/12/16 14:00:36 by ljylhank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

bool	is_stack_sorted(t_stack_node *a)
{
	int	last_value;

	last_value = INT_MIN;
	while (a)
	{
		if (last_value <= a->val)
			last_value = a->val;
		else
			return (false);
		a = a->next;
	}
	return (true);
}

static inline void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	if (get_stack_len(*a) == 1)
		return ;
	if (get_stack_len(*a) == 2)
		swap_a(a);
	else if (get_stack_len(*a) == 3)
		sort_three(a);
	else
		sort_all(a, b);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (print_error_exit());
	argv++;
	if (argc == 2)
	{
		argv = ft_split(*argv, ' ');
		argc = -1;
	}
	if (!assign_stack_values(&a, argv, argc))
		return (print_error_exit());
	if (argc == -1)
		free_str_array(argv);
	if (!is_stack_sorted(a))
		sort_stacks(&a, &b);
	free_stack(a);
	return (0);
}
