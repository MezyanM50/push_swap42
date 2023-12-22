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

void error_detect()
{
	ft_printf("error");
	exit(0);
}

void error_hunter(int i, char **s)
{
	int tmp;
	int j;

	while (s[i])
	{
		if (is_number(s[i]))
			error_detect();
		tmp = ft_atoi(s[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			error_detect();
		i++;
	}
}

int main(int argc,char **argv)
{
	if (argc > 1)
	{
		if (argc == 2)
		{
			argv = ft_split(argv[1], ' ');
			error_hunter(0, argv);
		}
		else
			error_hunter(1, argv);
	}
	return (0);
}
