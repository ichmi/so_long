/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:06:15 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/04/23 20:49:10 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft__isspace(const char ch)
{
	if ((ch >= 9 && ch <= 13) || ch == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	i = 0;
	while (ft__isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
	{
		result = (result * 10) + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}
