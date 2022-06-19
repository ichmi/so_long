/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:36:37 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/04/27 11:17:43 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*store;
	t_list	*p;

	p = *lst;
	if (!p)
		return ;
	while (p)
	{
		store = p->next;
		ft_lstdelone(p, del);
		p = store;
	}
	*lst = NULL;
}
