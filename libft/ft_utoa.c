/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:40:05 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/05/21 11:19:22 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft__ndigits(unsigned int num)
{
	int	digits;

	digits = 0;
	while (num)
	{
		digits++;
		num /= 10;
	}
	return (digits);
}

static void	ft__strrev(char *s)
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		temp = *(s + i);
		*(s + i++) = *(s + j);
		*(s + j--) = temp;
	}
}

static void	ft__wtobuff(char *s, unsigned int n)
{
	while (n)
	{
		*s++ = (n % 10) + '0';
		n /= 10;
	}
}

static char	*ft__newstr(size_t size)
{
	char	*p;

	p = (char *)ft_calloc((size + 1), sizeof(char));
	if (!p)
		return (NULL);
	return (p);
}

char	*ft_utoa(unsigned int n)
{
	char	*buff;

	if (n == 0)
		return (ft_strdup("0"));
	buff = ft__newstr(ft__ndigits(n));
	if (!buff)
		return (NULL);
	ft__wtobuff(buff, n);
	ft__strrev(buff);
	return (buff);
}
