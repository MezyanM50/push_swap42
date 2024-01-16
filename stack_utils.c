/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:45:45 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/16 16:52:44 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_any(t_stack **lst)
{
	int	tmp;

	tmp = (*lst)->value;
	(*lst)->value = (*lst)->next->value;
	(*lst)->next->value = tmp;
}

void	sa(t_stack **lst, int is_print)
{
	if (!lst || list_size(*lst) < 2)
		return ;
	swap_any(lst);
	if (is_print)
		write (1, "sa\n", 3);
}

void	sb(t_stack **lst, int is_print)
{
	if (!lst || list_size(*lst) < 2)
		return ;
	swap_any(lst);
	if (is_print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **lst_a, t_stack **lst_b, int is_print)
{
	sa(lst_a, 0);
	sb(lst_b, 0);
	if (is_print)
		write(1, "ss\n", 3);
}

void	push_any(t_stack **lst1, t_stack **lst2)
{
	t_stack	*tmp;
	t_stack	*next;

	tmp = (*lst2);
	next = tmp->next;
	(*lst2) = next;
	add_front(lst1, tmp);
}
