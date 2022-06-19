/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sides.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:02:46 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/19 15:13:19 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_up_down(char **matrix, int row)
{
	int invalid;
	int	j;

	j = 0;
	invalid = 0;
	while (matrix[0][j])
	{
		if (matrix[0][j] != '1')
			invalid++;
		j++;
	}
	row--;
	while (matrix[row][--j])
		if (matrix[row][j] != '1')
			invalid++;
	if (!invalid)
	{
		printf("matrix up-down: OK\n");
		return ;
	}
	printf("Error\ninvalid up-down map corner\n");
}

void	validate_left_right(char **matrix, int row, int col)
{
	int	invalid;
	int	i;

	i = 0;
	invalid = 0;
	while (++i < row && matrix[i][0])
		if (matrix[i][0] != '1')
			invalid++;
	col--;
	while (i-- && matrix[i][col])
		if (matrix[i][col] != '1')
			invalid++;
	if (!invalid)
	{
		printf("matrix left-right: OK\n");
		return ;
	}
	printf("Error\ninvalid left/right map corner\n");

}

void	validate_map_sides(t_map *map)
{
	validate_up_down(map->matrix, map->n_row);
	validate_left_right(map->matrix, map->n_row, map->n_col);
}
