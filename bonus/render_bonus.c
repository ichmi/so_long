/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:01:09 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/27 23:44:46 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	update_score(t_game *game)
{
	char	*s;

	s = ft_itoa(game->moves);
	mlx_put_image_to_window(game->id, game->window, game->img.score, 0, 0);
	if (game->size == 32)
		mlx_string_put(game->id, game->window, 8, 20, 0xffff00, s);
	else
		mlx_string_put(game->id, game->window, 18, 50, 0x000000, s);
	free(s);
}

static void	insert_map_sprite(t_game *game, char ch, int x, int y)
{
	void	*id;
	void	*window;

	x *= game->size;
	y *= game->size;
	id = game->id;
	window = game->window;
	if (ch == '1')
		mlx_put_image_to_window(id, window, game->img.wall, x, y);
	if (ch == '.')
		update_score(game);
	if (ch == '0')
		mlx_put_image_to_window(id, window, game->img.floor, x, y);
	if (ch == 'C')
		mlx_put_image_to_window(id, window, game->img.collect, x, y);
	if (ch == 'S')
		mlx_put_image_to_window(id, window, game->img.slime_l[0], x, y);
}

int	render_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.n_row)
	{
		j = -1;
		while (++j < game->map.n_col)
		{
			if (ft_strchr("1.0C", game->map.matrix[i][j]))
				insert_map_sprite(game, game->map.matrix[i][j], j, i);
			if (game->map.matrix[i][j] == 'P')
				player_animate(game, j, i);
			if (game->map.matrix[i][j] == 'E')
				exit_animate(game, j, i);
			if (game->map.found_slime && game->map.matrix[i][j] == 'S')
				slime_animate(game, j, i);
		}
	}
	usleep(60000);
	game->timer++;
	if (game->timer == 14)
		game->timer = 0;
	return (0);
}
