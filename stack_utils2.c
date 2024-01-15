/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:45:54 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/15 14:45:55 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "push_swap.h"

void    rotate_revesre_any(t_stack **lst)
{
    t_stack *last;
    t_stack *before_last;
    t_stack *tmp;

    before_last = *lst;
    last = list_last(*lst);
    tmp = *lst;
    while (tmp->next->next)
    {
        tmp = tmp->next;
        before_last = tmp;
    }
    last->next = *lst;
    *lst = last;
    before_last->next = NULL;
}


void rra(t_stack **lst_a,int is_print)
{
    if (!lst_a || list_size(*lst_a) < 2)
        return ;
    rotate_revesre_any(lst_a);
    if (is_print)
        printf("rra\n");
}

void rrb(t_stack **lst_b,int is_print)
{
    if (!lst_b || list_size(*lst_b) < 2)
        return ;
    rotate_revesre_any(lst_b);
    if (is_print)
        printf("rrb\n");
}

void rrr(t_stack **lst_a,t_stack **lst_b)
{
    rra(lst_a, 0);
    rrb(lst_b, 0);
    printf("rrr\n");
}

void pa(t_stack **lst_a,t_stack **lst_b)
{
    if (!lst_b)
        return ;
    push_any(lst_a,lst_b);
    printf("pa\n");
}
