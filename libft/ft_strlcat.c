/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:21:49 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/04/27 11:51:32 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = ft_strlen(dest);
	if (size < i)
		return (ft_strlen(src) + size);
	while (i < (size - 1) && *src)
		dest[i++] = *(src++);
	dest[i] = '\0';
	return (ft_strlen(src) + i);
}
