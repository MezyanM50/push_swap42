/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:03:12 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/20 12:09:50 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > (size_t)-1)
		return (NULL);
	buffer = read_from_fd(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = clean(buffer);
	if (line == NULL)
		free(buffer);
	return (line);
}

char	*read_from_fd(int fd, char *buf)
{
	ssize_t	b;
	char	*full_line;

	b = 1;
	full_line = (char *)malloc(BUFFER_SIZE + 1);
	while (b != 0)
	{
		b = read(fd, full_line, BUFFER_SIZE);
		if (b == -1)
		{
			free(full_line);
			return (NULL);
		}
		full_line[b] = '\0';
		buf = ft_strjoin(buf, full_line);
		if (check_newline(full_line))
			break ;
	}
	free(full_line);
	return (buf);
}

char	*extract_line(char *buf)
{
	int		i;
	char	*line;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] && buf[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*clean(char *buf)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] && buf[i] == '\n')
		i++;
	if (buf[i] == '\0')
	{
		free(buf);
		return (NULL);
	}
	str = malloc((ft_strlen(buf) - i) + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (buf[i])
		str[j++] = buf[i++];
	str[j] = '\0';
	free(buf);
	return (str);
}
