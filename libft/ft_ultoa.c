/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:15:53 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/05/18 17:41:11 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft__ndigits(unsigned long n, char *base)
{
	int	d;

	d = 0;
	if (n < ft_strlen(base))
		return (1);
	while (n)
	{
		n /= ft_strlen(base);
		d++;
	}
	return (d);
}

char	*ft_ultoa(unsigned long n, char *base)
{
	int		len;
	char	*s;

	if (!base || !*base)
		base = "0123456789";
	len = ft__ndigits(n, base);
	s = ft_calloc(len + 1, sizeof(char));
	if (!s)
		return (NULL);
	while (--len)
	{
		s[len] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	s[len] = base[n % ft_strlen(base)];
	return (s);
}
