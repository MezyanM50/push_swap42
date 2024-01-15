/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:50:30 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/10 13:15:51 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	oldi;
	int		count;

	len = ft_strlen(s);
	i = 0;
	count = 0 ;
	while (i < len)
	{
		while (i < len && s[i] == c)
			i++;
		oldi = i;
		while (i < len && s[i] != c)
			i++;
		if (i > oldi)
			count++;
	}
	return (count);
}

static void	ft_free(char **split, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(split[i++]);
	free(split);
}

static char	*ft_worddup(char *s, size_t start, size_t end)
{
	char	*str;
	size_t	len;
	int		i;

	len = end - start;
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

static char	**fill_split(char **split, char *s, char c)
{
	size_t	i;
	size_t	oldi;
	int		j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s))
	{
		while (i < ft_strlen(s) && s[i] == c)
			i++;
		oldi = i;
		while (i < ft_strlen(s) && s[i] != c)
			i++;
		if (i > oldi)
		{
			split[j] = ft_worddup((char *)s, oldi, i);
			if (!split[j++])
			{
				ft_free (split, j - 1);
				return (NULL);
			}
		}
	}
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		len;

	if (s == NULL)
		return (NULL);
	len = (ft_count_words((char *)s, c) + 1);
	split = (char **)malloc (sizeof(char *) * len);
	if (split == NULL)
		return (NULL);
	split = fill_split(split, (char *)s, c);
	return (split);
}
