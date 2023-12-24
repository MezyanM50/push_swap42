#include "push_swap.h"

t_stack *lastlist(t_stack *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

void addback(int n, int index, t_stack **list)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	new->value = malloc(sizeof(int));
	new->index = malloc(sizeof(int));
	new->value = n;
	new->index = index;
	new->next = NULL;
	if (!list)
	{
		(*list) = new;
		return ;
	}
	(*list) = lastlist(*list);
	(*list)->next = new;
}