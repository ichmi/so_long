/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:01:09 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/21 02:52:49 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	insert_sprite(char *sprite, t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->id, game->window, sprite, x * 64, y * 64);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.n_row)
	{
		j = -1;
		while (++j < game->map.n_col)
		{
			if (game->map.matrix[i][j] == '1')
				insert_sprite(game->img.wall, game, j, i);
			if (game->map.matrix[i][j] == '0')
				insert_sprite(game->img.floor, game, j, i);
			if (game->map.matrix[i][j] == 'C')
				insert_sprite(game->img.collect, game, j, i);
			if (game->map.matrix[i][j] == 'P')
				insert_sprite(game->img.char_r1, game, j, i);
			if (game->map.matrix[i][j] == 'E')
				insert_sprite(game->img.exit_open, game, j, i);
		}
	}
}
