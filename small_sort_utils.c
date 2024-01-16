/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:45:35 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/16 16:59:12 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *lst)
{
	int	max;

	max = lst->value;
	while (lst->next)
	{
		if (max < lst->next->value)
			max = lst->next->value;
		lst = lst->next;
	}
	return (max);
}

int	get_min(t_stack *lst)
{
	int	min;

	min = lst->value;
	while (lst->next)
	{
		if (min > lst->next->value)
			min = lst->next->value;
		lst = lst->next;
	}
	return (min);
}

void	sort_three(t_stack **lst_a)
{
	int		max;
	int		min;
	t_stack	*last;

	min = get_min(*lst_a);
	max = get_max(*lst_a);
	last = list_last(*lst_a);
	if (last->value == max)
		sa(lst_a, 1);
	else if (last->value == min)
	{
		if ((*lst_a)->value == max)
			sa(lst_a, 1);
		rra(lst_a, 1);
	}
	else
	{
		if ((*lst_a)->value != max)
			sa(lst_a, 1);
		ra(lst_a, 1);
	}
}

void	sort_four_util(t_stack **lst_a, t_stack **lst_b)
{
	if (is_list_sorted(*lst_a))
		return ;
	pb(lst_a, lst_b, 1);
	sort_three(lst_a);
	pa(lst_a, lst_b, 1);
}

void	sort_four(t_stack **lst_a, t_stack **lst_b)
{
	int		min;
	t_stack	*tmp;

	min = get_min(*lst_a);
	tmp = *lst_a;
	while (tmp)
	{
		if (tmp->value == min)
		{
			if (tmp->index > 1)
			{
				if (tmp->index == 2)
					rra(lst_a, 1);
				rra(lst_a, 1);
			}
			else if (tmp->index != 0)
				sa(lst_a, 1);
		}
		tmp = tmp->next;
	}
	sort_four_util(lst_a, lst_b);
}
