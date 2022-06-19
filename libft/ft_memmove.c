/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:32:46 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/04/27 11:35:47 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*ps;
	unsigned char		*pd;

	if (src == dest || n == 0)
		return (dest);
	if (dest < src)
	{
		ps = (unsigned char *)src;
		pd = (unsigned char *)dest;
		while (n--)
			*pd++ = *ps++;
	}
	else
	{
		ps = (unsigned char *)src + (n - 1);
		pd = (unsigned char *)dest + (n - 1);
		while (n--)
			*pd-- = *ps--;
	}
	return (dest);
}
