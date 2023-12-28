#include "push_swap.h"

static void sort_three(t_stack **a)
{
	int i;

	i = get_max(*a);
	if (i == 2)
		sa(a);
	if (i == 0)
	{
		ra(a);
		if (isn_sorted(*a))
			sa(a);
	}
	if (i = 1)
	{
		rra(a);
		if (isn_sorted(*a))
			sa(a);
	}
}

static void sort_four(t_stack **a,t_stack **b)
{
	pa(a, b);
	sort_three(a);
	pb(a, b);
	if (isn_sorted(*a))
		ra(a);
}

static void sort_four(t_stack **a, t_stack **b)
{
	pa(a, b);
	sort_four(a, b);
	pb(a, b);
	if (isn_sorted(*a))
		ra(a);
}

void sort_small(t_stack **a,t_stack **b)
{
	if (listsize(*a) == 2 && isn_sorted(*a))
		sa(a);
	if (listsize(*a) == 3 && isn_sorted(*a))
		sort_three(a);
	if (listsize(*a) == 4 && isn_sorted(*a))
		sort_four(a, b);
	if (listsize(*a) == 5 && isn_sorted(*a))
		sort_five(a, b);
}