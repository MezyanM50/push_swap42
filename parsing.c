/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:45:08 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/15 14:58:47 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(0);
}

long	ft_new_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	if (!str[i])
		return (2147483650);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	if (str[i])
		return (2147483650);
	return (res * sign);
}

int	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
	return (1);
}

void	check_for_error(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_new_atoi(str[i]) > INT_MAX || ft_new_atoi(str[i]) < INT_MIN)
		{
			free_tab(str);
			print_error("Invalid Argument");
		}
		i++;
	}
}

int	is_list_sorted(t_stack *lst)
{
	t_stack	*next;

	while (lst->next)
	{
		next = lst->next;
		if (lst->value > next->value)
			return (0);
		lst = lst->next;
	}
	return (1);
}
