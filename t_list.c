#include "push_swap.h"

t_stack *lastlist(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack *listnew(int value, int index)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = index;
	new->next = NULL;
	return (new);
}

void list_addback(t_stack *new,t_stack **lst)
{
	t_stack	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void list_addfront(t_stack *new,t_stack **list)
{
	if (!list)
	{
		new->next = NULL;
		(*list) = new;
	}
	else
	{
		new->next = (*list);
		(*list) = new;
	}
}

int listsize(t_stack *a)
{
	int i;

	i = 0;
	while(a)
	{
		a = a->next;
		i++;
	}
}



