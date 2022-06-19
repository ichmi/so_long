/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 03:39:09 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/19 06:20:37 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"
#include <stdio.h>

void	display_matrix(t_map *map)
{
	int	i;
	int	j;
	
	i = 0;
	while (map->matrix[i])
	{
		j = 0;
		while (map->matrix[i][j])
		{
			printf("%c", map.matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
