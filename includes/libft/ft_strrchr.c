/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:51:02 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/06 15:49:38 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	char			*str;
	unsigned char	ch;

	ch = (unsigned char)c;
	str = (char *)s;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if ((unsigned char)str[i] == ch)
			return (str + i);
		i--;
	}
	return (NULL);
}
