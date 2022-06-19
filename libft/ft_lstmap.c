/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:47:55 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/04/27 11:23:28 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*buff;
	t_list	*node;

	if (!lst)
		return (NULL);
	buff = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&buff, del);
			return (NULL);
		}
		ft_lstadd_back(&buff, node);
		lst = lst->next;
	}
	return (buff);
}
