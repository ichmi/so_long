/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:36:09 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/04/27 14:18:44 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b_len;
	size_t	l_len;
	size_t	size;

	if (!*little)
		return ((char *)big);
	b_len = ft_strlen(big);
	l_len = ft_strlen(little);
	if (len < l_len || b_len < l_len)
		return (NULL);
	if (b_len > len)
		size = len;
	else
		size = b_len;
	while (size-- >= l_len)
	{
		if (ft_strncmp(big, little, l_len) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
