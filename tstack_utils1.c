/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstack_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:24:55 by mmezyan           #+#    #+#             */
/*   Updated: 2024/01/18 14:33:49 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	must_split(char *s)
{
	int i;
	int count;

	i = 1;
	count = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) && s[i - 1] == ' ')
			count++;
		i++;
	}
	return (count);
}

unsigned int    count_args(char **str)
{
    int i;
    unsigned int count;
    
    i = 0;
    count = 0;
    while (str[i]) 
    {
        if (must_split(str[i]))
            count += must_split(str[i]);
        count++;
        i++;
    }  
    return (count);
}
