#include "push_swap.h"

int swap(t_stack **lst)
{
    t_stack *head;
    t_stack *next;
    int     value;
    int     index;

    head = (*lst);
    if (listsize(head) < 2)
        return (0);
    next = head->next;
    value = head->value;
    index = head->index;
    head->value = next->value;
    head->index = next->index;
    next->value = value;
    next->index = index;
    return (1);
}

void sa(t_stack **a)
{
    if (!swap(a))
        return ;
    ft_printf("sa\n");
}

void sb(t_stack **b)
{
    if(!swap(b))
        return ;
    ft_printf("sa\n");
}

void ss(t_stack **a,t_stack **b)
{
    if (!swap(a) || !swap(b))
        return ;
    ft_printf("ss\n");
}

int push(t_stack **a,t_stack **b)
{
    t_stack *new;
    t_stack *tmp;

    new = malloc(sizeof(t_stack));
    if (!b)
        return (0);
    new->index = (*b)->index;
    new->value = (*b)->value;
    list_addfront(new, a);
    tmp = (*b);
    (*b) = (*b)->next;
    tmp->index = 0;
    tmp->next = NULL;
    tmp->value = 0;
    free(tmp);
    return (1);
}

void pa(t_stack **a,t_stack **b)
{
    if (!push(a,b))
        return ;
    ft_printf("pa\n");
}

void pb(t_stack **a,t_stack **b)
{
    if (!push(b,a))
        return ;
    ft_printf("pb\n");
}

int rotate(t_stack **a)
{
    t_stack *head;
    t_stack *tail;
    t_stack *tmp;

    if (listsize(*a) < 2)
        return (0);
    head = (*a);
    tail = lastlist(head);
    tmp = head->next;
    tail->next = head;
    head->next = NULL;
    (*a) = tmp;
    return (1);
}

void ra(t_stack **a)
{
    if (!rotate(a))
        return ;
    ft_printf("ra\n");
}

void rb(t_stack **b)
{
    if (!rotate(b))
        return ;
    ft_printf("rb\n");
}

void rr(t_stack **b, t_stack **a)
{
    if (!rotate(a) || !rotate(b))
        return ;
    ft_printf("rr\n");
}

int reverse_rotate(t_stack **a)
{
	t_stack *head;
	t_stack *tail;
	t_stack *tmp;

	if (listsize(*a) < 2)
		return (0);
	head = (*a);
	tmp = (*a);
	tail = lastlist(head);
	while (head->next->next)
		head = head->next;
	head->next = NULL;
	tail->next = tmp;
	(*a) = tail;
	return (1);
}

void rra(t_stack **a)
{
	if (!reverse_rotate(a))
		return ;
	ft_printf("rra\n");
}

void rrb(t_stack **b)
{
	if (!reverse_rotate(b))
		return ;
	ft_printf("rrb\n");
}

void rrr(t_stack **a,t_stack **b)
{
	if (!reverse_rotate(a) || !reverse_rotate(b))
		return ;
	ft_printf("rrr\n");
}