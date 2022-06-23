/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_attributes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:12:50 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/22 21:10:41 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_attributes(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->matrix[i])
	{
		j = 0;
		while (map->matrix[i][j])
		{
			if (map->matrix[i][j] == 'P')
				map->p++;
			if (map->matrix[i][j] == 'C')
				map->c++;
			if (map->matrix[i][j] == 'E')
				map->e++;
			j++;
		}
		i++;
	}
}

void	validate_allowed_attributes(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->matrix[i])
	{
		j = 0;
		while (map->matrix[i][j])
		{
			if (!ft_strchr("10PCE", map->matrix[i][j]))
			{
				ft_printf("Error\nInvalid map attribute\n");
				ft_free_matrix(map->matrix);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	validate_map_attributes(t_map *map)
{
	map->p = 0;
	map->c = 0;
	map->e = 0;
	validate_allowed_attributes(map);
	get_map_attributes(map);
	if (map->p == 1 && map->c > 0 && map->e == 1)
		return ;
	ft_printf("Error\nMissing map attributes\n");
	ft_free_matrix(map->matrix);
	exit(1);
}
