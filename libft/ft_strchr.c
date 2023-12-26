/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:44:11 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/06 15:47:05 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*str;
	unsigned char	ch;

	i = 0;
	str = (char *)s;
	ch = (unsigned char)c;
	if (ch == 0)
		return (&str[ft_strlen(str)]);
	while (str[i])
	{
		if (ch == (unsigned char)str[i])
			return (str + i);
		i++;
	}
	return (NULL);
}
