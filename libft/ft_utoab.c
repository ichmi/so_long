/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:11:27 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/05/23 14:34:25 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft__ndigits(unsigned int n, char *base)
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

char	*ft_utoab(unsigned int n, char *base)
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
