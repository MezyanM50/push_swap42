/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:44:46 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/15 14:44:52 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void go_back_to_a(t_stack **lst_a,t_stack **lst_b)
{
    int i;
    t_stack *tmp;
    t_stack *max;

    i = 0;
    tmp = *lst_b;
    while (tmp)
    {
        max = get_node_max(lst_b);
        if (max->index > list_size(*lst_b) / 2)
        {
            while ((*lst_b)->value != max->value)
                rrb(lst_b, 1);
            pa(lst_a,lst_b);
        }
        else
        {
            while ((*lst_b)->value != max->value)
                rb(lst_b, 1);
            pa(lst_a,lst_b);
        }
        i++; 
        initiate_index(lst_b);
        tmp = *lst_b;
    }
}

void long_sort(t_stack **lst_a,t_stack **lst_b)
{
    t_chunk chunk;
    int i;
    t_stack *tmp;
    int size;

    size = list_size(*lst_a);
    i = 0;
    fill_and_sort_arr(&chunk,lst_a);
    chunk.n = get_range(size);
    chunk.start = 0 ;
    chunk.end = chunk.n - 1 ;
    tmp = *lst_a;
    while (tmp)
    {
        if (tmp->value <= chunk.sorted_arr[chunk.start])
        {
            pb(lst_a,lst_b);
            rb(lst_b, 1);
            if (chunk.end < size - 1)
                chunk.end++;
            if (chunk.start < chunk.end)
                chunk.start++;        
        }
        else if (tmp->value > chunk.sorted_arr[chunk.start] && tmp->value <= chunk.sorted_arr[chunk.end])
        {
             pb(lst_a,lst_b);
            if (list_size((*lst_b)) && (*lst_b)->next &&(*lst_b)->value < (*lst_b)->next->value)
                sb(lst_b, 1);
            if (chunk.end < size - 1)
                chunk.end++;
            if (chunk.start < chunk.end)
                chunk.start++;
        }
        else 
            ra(lst_a, 1);
        tmp = *lst_a;   
    }
    initiate_index(lst_b);
    go_back_to_a(lst_a,lst_b);
}




