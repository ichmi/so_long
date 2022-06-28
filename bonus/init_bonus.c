/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:50:09 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/28 04:28:03 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_player_sprites(t_game *game)
{
	char	*xpm;
	int		i;

	i = 0;
	while (i < 7)
	{
		xpm = get_xpm_file("r", game, i + 1);
		game->img.char_r[i] = get_sprite(xpm, game);
		free(xpm);
		xpm = get_xpm_file("l", game, i + 1);
		game->img.char_l[i] = get_sprite(xpm, game);
		free(xpm);
		xpm = get_xpm_file("b", game, i + 1);
		game->img.char_b[i++] = get_sprite(xpm, game);
		free(xpm);
	}
	i = 0;
	while (i < 6)
	{
		xpm = get_xpm_file("t", game, i + 1);
		game->img.char_t[i++] = get_sprite(xpm, game);
		free(xpm);
	}
	game->img.fox_sprite = game->img.char_r[0];
}

static void	init_map_sprites(t_game *game)
{
	if (game->size == 32)
		init_32px_xpm(game);
	else
		init_64px_xpm(game);
}

static void	init_window(t_game *game)
{
	int		display_w;
	int		display_h;
	int		x;
	int		y;

	x = game->map.n_col * game->size;
	y = game->map.n_row * game->size;
	game->id = mlx_init();
	mlx_get_screen_size(game->id, &display_w, &display_h);
	if (x > display_w || y > display_h)
	{
		x /= 2;
		y /= 2;
		game->size = 32;
		game->window = mlx_new_window(game->id, x, y, "so_long (frosa-ma)");
	}
	else
		game->window = mlx_new_window(game->id, x, y, "so_long (frosa-ma)");
	game->map.matrix[0][0] = '.';
	set_game_objective(game);
}

void	init_game(t_game *game)
{
	init_window(game);
	init_map_sprites(game);
	init_player_sprites(game);
	init_event_handler(game);
}
