#include "push_swap.h"

void cheker(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "Error\n",6);
	if (stack_a)
		free_list(stack_a);
	if (stack_b)
		free_list(stack_b);
	exit(0);
}

int check_operation(char *s)
{
	if (ft_strlen(s) == 3 && s[0] == 's' && s[1] == 'a' && s[2] == '\n')
		return (1);
	else if (ft_strlen(s) == 3 && s[0] == 's' && s[1] == 'b' && s[2] == '\n')
		return (2);
	else if (ft_strlen(s) == 3 && s[0] == 's' && s[1] == 's' && s[2] == '\n')
		return (3);
	else if (ft_strlen(s) == 3 && s[0] == 'r' && s[1] == 'a' && s[2] == '\n')
		return (4);
	else if (ft_strlen(s) == 3 && s[0] == 'r' && s[1] == 'b' && s[2] == '\n')
		return (5);
	else if (ft_strlen(s) == 3 && s[0] == 'r' && s[1] == 'r' && s[2] == '\n')
		return (6);
	else if (ft_strlen(s) == 3 && s[0] == 'p' && s[1] == 'a' && s[2] == '\n')
		return (7);
	else if (ft_strlen(s) == 3 && s[0] == 'p' && s[1] == 'b' && s[2] == '\n')
		return (8);
	else if (ft_strlen(s) == 4 && s[0] == 'r' && s[1] == 'r' && s[2] == 'r' && s[3] == '\n')
		return (9);
	else if (ft_strlen(s) == 4 && s[0] == 'r' && s[1] == 'r' && s[2] == 'b' && s[3] == '\n')
		return (10);
	else if (ft_strlen(s) == 4 && s[0] == 'r' && s[1] == 'r' && s[2] == 'a' && s[3] == '\n')
		return (11);
	return (0);
}

void check_operation_doit(char *s, t_stack **stack_a, t_stack **stack_b)
{
	if (check_operation(s) == 0)
		cheker(stack_a,stack_b);
	else if (check_operation(s) == 1)
		sa(stack_a, 0);
	else if (check_operation(s) == 2)
		sb(stack_b, 0);
	else if (check_operation(s) == 3)
		ss(stack_a, stack_b, 0);
	else if (check_operation(s) == 4)
		ra(stack_a, 0);
	else if (check_operation(s) == 5)
		rb(stack_b, 0);
	else if (check_operation(s) == 6)
		rr(stack_a, stack_b, 0);
	else if (check_operation(s) == 7)
		pa(stack_a, stack_b, 0);
	else if (check_operation(s) == 8)
		pb(stack_a, stack_b, 0);
	else if (check_operation(s) == 9)
		rrr(stack_a, stack_b, 0);
	else if (check_operation(s) == 10)
		rrb(stack_b, 0);
	else if (check_operation(s) == 11)
		rra(stack_a, 0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**str;
	char	*s;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
		str = ft_split(argv[1], ' ');
	else
		str = allocate_str(argv, argc);
	check_for_error(str);
	fill_stack(str, &stack_a);
	while (1)
	{
		s = get_next_line(0);	
		if (!s)
			break;
		check_operation_doit(s, &stack_a, &stack_b);
		free(s);
	}
	if (is_list_sorted(stack_a) && list_size(stack_b) == 0)
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
	free_list(&stack_a);
	return (0);
}
