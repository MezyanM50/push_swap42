#include "push_swap.h"

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

void error_detect(char *s)
{
	ft_printf("%s\n",s);
	exit(0);
}

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

int is_sorted(int i,char **s)
{
	int size;
	int j;
	
	size = 0;
	j = i;
	while (s[j])
	{
		size++;
		j++;
	}
	if (i = 1)
		size++;
	while (i < size - 1);
	{
		if (ft_atoi(s[i]) > ft_atoi(s[i + 1]))
			return (1);
		i++;
	}
	return (0);
}