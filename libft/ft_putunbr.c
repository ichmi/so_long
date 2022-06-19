/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:26:58 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/05/18 17:00:04 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putunbr(unsigned int n)
{
	int	bw;

	bw = 0;
	if (n > 9)
		bw += ft_putunbr(n / 10);
	bw += ft_putchar((n % 10) + '0');
	return (bw);
}