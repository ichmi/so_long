/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:06:10 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/05/27 20:48:53 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnstr(char *s, int n)
{
	int	bw;

	if (!s)
		return (write(1, "(null)", 6));
	bw = 0;
	while (*s && n--)
	{
		bw += ft_putchar(*s);
		s++;
	}
	return (bw);
}
