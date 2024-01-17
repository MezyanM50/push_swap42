/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:45:41 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/17 13:41:55 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_util(t_stack **lst_a, t_stack **lst_b)
{
	if (is_sorted(*lst_a))
		return ;
	pb(lst_a, lst_b, 1);
	initiate_index(lst_a);
	sort_four(lst_a, lst_b);
	pa(lst_a, lst_b, 1);
}

void	sort_five(t_stack **lst_a, t_stack **lst_b)
{
	int		min;
	t_stack	*tmp;

	min = get_min(*lst_a);
	tmp = *lst_a;
	while (tmp)
	{
		if (tmp->value == min)
		{
			if (tmp->index > 2)
			{
				if (tmp->index == 3)
					rra(lst_a, 1);
				rra(lst_a, 1);
			}
			else if (tmp->index != 0)
			{
				if (tmp->index == 2)
					ra(lst_a, 1);
				ra(lst_a, 1);
			}
		}
		tmp = tmp->next;
	}
	sort_five_util(lst_a, lst_b);
}

void	sort_algo(t_stack **lst_a, t_stack **lst_b)
{
	(void)lst_b;
	if (list_size(*lst_a) == 2)
		sa(lst_a, 1);
	else if (list_size(*lst_a) == 3)
		sort_three(lst_a);
	else if (list_size(*lst_a) == 4)
		sort_four(lst_a, lst_b);
	else if (list_size(*lst_a) == 5)
		sort_five(lst_a, lst_b);
	else
		long_sort(lst_a, lst_b);
}
