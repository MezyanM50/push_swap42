/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:45:17 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/17 13:41:55 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**str;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		print_error("Error");
	if (argc == 2)
		str = ft_split(argv[1], ' ');
	else
		str = alloc_str(argv, argc);
	check_for_error(str);
	fill_stack(str, &stack_a);
	if (is_sorted(stack_a) && free_list(&stack_a))
		return (0);
	sort_algo(&stack_a, &stack_b);
	free_list(&stack_a);
}
