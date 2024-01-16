/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:45:50 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/16 17:07:36 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_any(t_stack **lst)
{
	t_stack	*head;
	t_stack	*next;
	t_stack	*tmp;

	head = *lst;
	next = head->next;
	tmp = list_last(*lst);
	*lst = next;
	tmp->next = head;
	head->next = NULL;
}

void	ra(t_stack **lst_a, int is_print)
{
	if (!lst_a || list_size(*lst_a) < 2)
		return ;
	rotate_any(lst_a);
	if (is_print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **lst_b, int is_print)
{
	if (!lst_b || list_size(*lst_b) < 2)
		return ;
	rotate_any(lst_b);
	if (is_print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **lst_b, t_stack **lst_a, int is_print)
{
	ra(lst_a, 0);
	rb(lst_b, 0);
	if (is_print)
		write(1, "rr\n", 3);
}

void	pb(t_stack **lst_a, t_stack **lst_b, int is_print)
{
	if (!lst_a || list_size(*lst_a) < 1)
		return ;
	push_any(lst_b, lst_a);
	if (is_print)
		write(1, "pb\n", 3);
}
