#include "push_swap.h"


void fill_stack(int ac,char **s,t_stack **lst)
{
	t_stack *new;
	int i;

	i = 0;
	if (ac == 2)
		i = 1;
	while (s[i])
	{
		new = listnew(ft_atoi(s[i]), i);
		list_addback(new, lst);
		i++;
	}
}

int main(int argc,char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		if (argc == 2)
		{
			argv = ft_split(argv[1], ' ');
			error_hunter(0,argv);
		}
		else
		{
			error_hunter(1,argv);
		}
		fill_stack(argc,argv,&a);
	}
	return (0);
}
