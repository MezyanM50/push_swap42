/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:27:44 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/10 11:41:06 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	finish;
	char	*str;

	if (!s)
		return (NULL);
	finish = 0;
	if (start < ft_strlen(s))
		finish = ft_strlen(s) - start;
	if (finish > len)
		finish = len;
	str = (char *) malloc(finish + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < finish)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
