/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:12:27 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/04/23 20:39:32 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	if ((ft_strlen(src) + 1) < n)
		ft_memcpy(dest, src, (ft_strlen(src) + 1));
	else if (n != 0)
	{
		ft_memcpy(dest, src, n - 1);
		dest[n - 1] = '\0';
	}
	return (ft_strlen(src));
}
