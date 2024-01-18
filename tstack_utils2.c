/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstack_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:46:02 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/18 11:25:15 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_double(t_stack *lst)
{
	t_stack	*tmp;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (lst->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (0);
}

void	fill_stack(char **str, t_stack **stack_a)
{
	t_stack	*new;
	int		i;

	i = 0;
	while (str[i])
	{
		new = create_new(ft_new_atoi(str[i]), i);
		add_back(stack_a, new);
		if (check_for_double(*stack_a) == 1 && free_tab(str)
			&& free_list(stack_a))
			print_error("Invalid Argument");
		i++;
	}
	free_tab(str);
}

int	free_list(t_stack **lst)
{
	t_stack	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	return (1);
}

char	**alloc_str(char **argv, int argc)
{
	int		i;
	int		j;
	char	**str;
	char	*tmp;

	i = 1;
	j = 0;
	str = (char **)malloc(sizeof(char *) * argc);
	while (i < argc)
	{
		
		tmp = ft_strdup(argv[i]);
		if (!tmp)
			return (NULL);
		str[j] = tmp;
		i++;
		j++;
	}
	str[j] = NULL;
	return (str);
}
