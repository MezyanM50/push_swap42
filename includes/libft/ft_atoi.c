/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:13:02 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/10 11:24:03 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					s;
	unsigned long		r;

	i = 0;
	s = 1;
	r = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		r = (r * 10) + (str[i] - 48);
		i++;
	}
	return (r * s);
}
