/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstack_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:46:02 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/15 15:36:29 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_stack(t_stack *lst)
{
	printf("| %-10s | %-5s | %-5s | %-5s |\n", "Value", "Index", "After Middle",
		"Cost");
	printf("|------------|-------|--------------|-------|\n");
	while (lst)
	{
		printf("| %-10d | %-5d | %-12s |\n", lst->value, lst->index,
			lst->is_after_middle ? "Yes" : "No");
		lst = lst->next;
	}
	printf("\n");
}

char	**allocate_str(char **argv, int argc)
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
