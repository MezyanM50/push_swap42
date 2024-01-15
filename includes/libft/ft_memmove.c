/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:07:18 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/10 11:23:42 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	if (!dst && !src)
		return (dst);
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (d > s)
	{
		while (len-- > 0)
			d[len] = s[len];
	}
	else
		ft_memcpy(d, s, len);
	return (d);
}
