/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:44:45 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/17 14:01:59 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker(t_stack **stack_a, t_stack **stack_b, int is_print)
{
	if (is_print)
		write(1, "Error\n", 6);
	if (*stack_a)
		free_list(stack_a);
	if (*stack_b)
		free_list(stack_b);
	exit(0);
}

void	finisher(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a) && list_size(*stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	checker(stack_a, stack_b, 0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**str;
	char	*s;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
		str = ft_split(argv[1], ' ');
	else
		str = alloc_str(argv, argc);
	check_for_error(str);
	fill_stack(str, &stack_a);
	while (1)
	{
		s = get_next_line(0);
		if (!s)
			break ;
		check_operation_doit(s, &stack_a, &stack_b);
		free(s);
	}
	finisher(&stack_a, &stack_b);
	return (0);
}
