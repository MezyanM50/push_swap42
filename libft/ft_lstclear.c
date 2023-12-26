/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 14:19:48 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/06 15:38:47 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*current;

	if (!lst && !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		current = tmp;
		tmp = tmp->next;
		del(current->content);
		free(current);
	}
	*lst = 0;
}
