/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_sides_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:02:46 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/22 23:02:44 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	validate_up_down(char **matrix, int row)
{
	int	invalid;
	int	j;

	j = 0;
	--row;
	invalid = 0;
	while (matrix[0][j])
	{
		if (matrix[0][j] != '1' || matrix[row][j] != '1')
			invalid++;
		j++;
	}
	if (!invalid)
		return ;
	ft_printf("Error\nInvalid up/down map side\n");
	ft_free_matrix(matrix);
	exit(1);
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
		return ;
	ft_printf("Error\nInvalid left/right map side\n");
	ft_free_matrix(matrix);
	exit(1);
}

void	validate_map_sides(t_map *map)
{
	validate_up_down(map->matrix, map->n_row);
	validate_left_right(map->matrix, map->n_row, map->n_col);
}
