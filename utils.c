#include "push_swap.h"

int get_max(t_stack *a)
{
	t_stack *max;

	max = a;
	while (a)
	{
		if (max->value < a->value)
			max = a;
		a = a->next;
	}
	return (max->index);
}