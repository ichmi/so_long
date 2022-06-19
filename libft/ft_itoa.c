/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 12:32:01 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/04/25 23:07:32 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft__ndigits(int num)
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

static void	ft__wtobuff(char *s, int n, int is_nve)
{
	if (is_nve)
		*s++ = '-';
	while (n)
	{
		*s++ = (n % 10) + '0';
		n /= 10;
	}
}

static char	*ft__newstr(size_t size, int nve)
{
	char	*p;

	if (nve)
		p = (char *)ft_calloc((size + 2), sizeof(char));
	else
		p = (char *)ft_calloc((size + 1), sizeof(char));
	if (!p)
		return (NULL);
	return (p);
}

char	*ft_itoa(int n)
{
	char	*buff;
	int		nve;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nve = 0;
	if (n < 0)
	{
		nve = 1;
		n *= -1;
	}
	buff = ft__newstr(ft__ndigits(n), nve);
	if (!buff)
		return (NULL);
	ft__wtobuff(buff, n, nve);
	if (nve)
	{
		ft__strrev(buff + 1);
		return (buff);
	}
	ft__strrev(buff);
	return (buff);
}
