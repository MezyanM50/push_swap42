/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:44:39 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/15 14:52:49 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void selection_sort(t_chunk *chunk,int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < size)
    {
        j = 0 ;
        while (j < i)
        {
            if (chunk->sorted_arr[i] < chunk->sorted_arr[j])
            {
                tmp = chunk->sorted_arr[i];
                chunk->sorted_arr[i] = chunk->sorted_arr[j];
                chunk->sorted_arr[j] = tmp;
            }
            j++;
        }
        i++;
    } 
}

int get_range(int size)
{
    
    if (size >= 6 && size <= 16)
        return (3);
    else if (size <= 100)
        return (14);
    else if (size <= 500)
        return (35);
    return (0);
}
void fill_and_sort_arr(t_chunk *chunk,t_stack **lst_a)
{
    t_stack *tmp;
    int i;

    i = 0;
    chunk->sorted_arr  = (int *)malloc(list_size(*lst_a) * sizeof(int));
    if (!chunk->sorted_arr)
        return ;
    tmp = *lst_a;
    while (tmp)
    {
        chunk->sorted_arr[i++] = tmp->value;
        tmp = tmp->next;
    }   
    selection_sort(chunk,list_size(*lst_a));
}

void initiate_index(t_stack **lst_b)
{
    int i;
    t_stack *tmp;

    i = 0;
    tmp = *lst_b;
    while (i < list_size(*lst_b))
    {
        tmp->index = i;
        tmp = tmp->next;
        i++;
    } 
}

t_stack *get_node_max(t_stack **lst_b)
{
    t_stack    *tmp;
    t_stack *max_node;

    tmp = *lst_b;
    max_node = *lst_b;
    while (tmp)
    {
        if (tmp->value > max_node->value)
            max_node = tmp;
        tmp = tmp->next;
    }
    return (max_node);
}