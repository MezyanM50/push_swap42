/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:04:25 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/20 12:14:57 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strjoin_len(char *buf, char *full_line)
{
	int	total_len;

	total_len = 0;
	if (!buf)
		total_len = ft_strlen(full_line);
	else
		total_len = ft_strlen(full_line) + ft_strlen(buf);
	return (total_len);
}

char	*ft_strjoin(char *buf, char *full_line)
{
	char		*str;
	int			i;
	int			j;
	int			total_len;

	if (!full_line)
		return (NULL);
	total_len = ft_strjoin_len(buf, full_line);
	str = malloc(total_len + 1);
	if (!str)
		return (NULL);
	j = 0;
	if (buf)
	{
		i = 0;
		while (buf[i] != '\0')
			str[j++] = buf[i++];
	}
	i = 0;
	while (full_line[i] != '\0')
		str[j++] = full_line[i++];
	str[j] = '\0';
	if (buf)
		free(buf);
	return (str);
}

int	check_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
