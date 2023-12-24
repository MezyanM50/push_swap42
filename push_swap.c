#include "push_swap.h"

int is_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void error_detect(char *s)
{
	ft_printf("%s\n",s);
	exit(0);
}

void error_hunter(int i,char **s)
{
	long tmp;

	while (s[i])
	{
		if (is_number(s[i]))
			error_detect("error the number not valid");
		tmp = ft_atoi(s[i]);
		if (tmp > 2147483647 || tmp < -2147483648)
			error_detect("error the number not valid");
		i++;
	}
}

void fill_stack(int i,char **s,t_stack **lst)
{
	t_stack *new;

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
	int i;
	t_stack	*b;

	a = NULL;
	b = NULL;
	i = 0;
	if (argc > 1)
	{
		if (argc == 2)
		{
			argv = ft_split(argv[1], ' ');
			error_hunter(i,argv);
		}
		else
		{
			i++;
			error_hunter(i,argv);
		}
		fill_stack(i,argv,&a);
	}
	

	return (0);
}
