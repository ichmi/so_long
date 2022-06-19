/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:24:11 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/05/18 16:37:29 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *p)
{
	char			*s;
	int				bw;

	bw = 0;
	if (!p)
		return (write(1, "(nil)", 5));
	bw += write(1, "0x", 2);
	s = ft_ultoa((unsigned long)p, "0123456789abcdef");
	if (!s)
		return (0);
	bw += ft_putstr(s);
	free(s);
	return (bw);
}
