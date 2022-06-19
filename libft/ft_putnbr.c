/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:36:18 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/05/18 14:39:28 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	char	*int_min;
	int		bw;

	bw = 0;
	if (n == -2147483648)
	{
		int_min = ft_strdup("-2147483648");
		bw += ft_putstr(int_min);
		free(int_min);
		return (bw);
	}
	if (n < 0)
	{
		bw += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		bw += ft_putnbr(n / 10);
	bw += ft_putchar((n % 10) + '0');
	return (bw);
}
