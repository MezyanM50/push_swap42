/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:57:13 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/17 14:02:56 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_operation_util(char *s)
{
	if (ft_strlen(s) == 4 && s[0] == 'r' && s[1] == 'r' && s[2] == 'r'
		&& s[3] == '\n')
		return (9);
	else if (ft_strlen(s) == 4 && s[0] == 'r' && s[1] == 'r' && s[2] == 'b'
		&& s[3] == '\n')
		return (10);
	else if (ft_strlen(s) == 4 && s[0] == 'r' && s[1] == 'r' && s[2] == 'a'
		&& s[3] == '\n')
		return (11);
	return (0);
}

int	check_operation(char *s)
{
	if (ft_strlen(s) == 3 && s[0] == 's' && s[1] == 'a' && s[2] == '\n')
		return (1);
	else if (ft_strlen(s) == 3 && s[0] == 's' && s[1] == 'b' && s[2] == '\n')
		return (2);
	else if (ft_strlen(s) == 3 && s[0] == 's' && s[1] == 's' && s[2] == '\n')
		return (3);
	else if (ft_strlen(s) == 3 && s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		return (4);
	else if (ft_strlen(s) == 3 && s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		return (5);
	else if (ft_strlen(s) == 3 && s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
		return (6);
	else if (ft_strlen(s) == 3 && s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		return (7);
	else if (ft_strlen(s) == 3 && s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		return (8);
	else
		return (check_operation_util(s));
	return (0);
}

void	check_operation_doit(char *s, t_stack **stack_a, t_stack **stack_b)
{
	if (check_operation(s) == 0)
		checker(stack_a, stack_b, 1);
	else if (check_operation(s) == 1)
		sa(stack_a, 0);
	else if (check_operation(s) == 2)
		sb(stack_b, 0);
	else if (check_operation(s) == 3)
		ss(stack_a, stack_b, 0);
	else if (check_operation(s) == 4)
		ra(stack_a, 0);
	else if (check_operation(s) == 5)
		rb(stack_b, 0);
	else if (check_operation(s) == 6)
		rr(stack_a, stack_b, 0);
	else if (check_operation(s) == 7)
		pa(stack_a, stack_b, 0);
	else if (check_operation(s) == 8)
		pb(stack_a, stack_b, 0);
	else if (check_operation(s) == 9)
		rrr(stack_a, stack_b, 0);
	else if (check_operation(s) == 10)
		rrb(stack_b, 0);
	else if (check_operation(s) == 11)
		rra(stack_a, 0);
}
