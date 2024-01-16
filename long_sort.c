/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:44:46 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/16 16:59:42 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_back_to_a(t_stack **lst_a, t_stack **lst_b)
{
	int		i;
	t_stack	*tmp;
	t_stack	*max;

	i = 0;
	tmp = *lst_b;
	while (tmp)
	{
		max = get_node_max(lst_b);
		if (max->index > list_size(*lst_b) / 2)
		{
			while ((*lst_b)->value != max->value)
				rrb(lst_b, 1);
			pa(lst_a, lst_b, 1);
		}
		else
		{
			while ((*lst_b)->value != max->value)
				rb(lst_b, 1);
			pa(lst_a, lst_b, 1);
		}
		i++;
		initiate_index(lst_b);
		tmp = *lst_b;
	}
}

void	move_chunk(int *start, int *end, int size)
{
	if (*end < size - 1)
		(*end)++;
	if (*start < *end)
		(*start)++;
}

void	sort_condition(t_stack **lst_a, t_stack **lst_b, t_chunk *chunk,
		int size)
{
	if ((*lst_a)->value <= chunk->array[chunk->start])
	{
		pb(lst_a, lst_b, 1);
		rb(lst_b, 1);
		move_chunk(&chunk->start, &chunk->end, size);
	}
	else if ((*lst_a)->value > chunk->array[chunk->start]
		&& (*lst_a)->value <= chunk->array[chunk->end])
	{
		pb(lst_a, lst_b, 1);
		if (list_size((*lst_b)) && (*lst_b)->next
			&& (*lst_b)->value < (*lst_b)->next->value)
			sb(lst_b, 1);
		move_chunk(&chunk->start, &chunk->end, size);
	}
	else
		ra(lst_a, 1);
}

void	long_sort(t_stack **lst_a, t_stack **lst_b)
{
	t_chunk	chunk;
	int		i;
	int		size;

	size = list_size(*lst_a);
	i = 0;
	fill_and_sort_arr(&chunk, lst_a);
	chunk.n = get_range(size);
	chunk.start = 0;
	chunk.end = chunk.n - 1;
	while ((*lst_a))
	{
		sort_condition(lst_a, lst_b, &chunk, size);
	}
	initiate_index(lst_b);
	go_back_to_a(lst_a, lst_b);
	free(chunk.array);
}
