/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:04:41 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/20 12:16:19 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_strjoin(char *buf, char *full_line);
size_t	ft_strlen(const char *str);
char	*read_from_fd(int fd, char *buf);
char	*get_next_line(int fd);
int		check_newline(char *str);
char	*extract_line(char *buf);
char	*clean(char *buf);
#endif
