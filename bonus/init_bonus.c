/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:50:09 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/27 00:20:06 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*get_sprite(char *pathname, void *id)
{
	int		width;
	int		height;

	width = SIZE;
	height = SIZE;
	return (mlx_xpm_file_to_image(id, pathname, &width, &height));
}

static void	init_player_sprites(t_game *game)
{
	char	*xpm;
	int		i;

	i = 0;
	while (i < 7)
	{
		xpm = get_xpm_file("r", i + 1);
		game->img.char_r[i] = get_sprite(xpm, game->id);
		free(xpm);
		xpm = get_xpm_file("l", i + 1);
		game->img.char_l[i] = get_sprite(xpm, game->id);
		free(xpm);
		xpm = get_xpm_file("b", i + 1);
		game->img.char_b[i++] = get_sprite(xpm, game->id);
		free(xpm);
	}
	i = 0;
	while (i < 6)
	{
		xpm = get_xpm_file("t", i + 1);
		game->img.char_t[i++] = get_sprite(xpm, game->id);
		free(xpm);
	}
	game->img.fox_sprite = game->img.char_r[0];
}

static void	init_map_sprites(t_game *game)
{
	void	*id;
	char	*xpm;
	int		i;

	id = game->id;
	game->img.floor = get_sprite("assets/floor.xpm", id);
	game->img.wall = get_sprite("assets/wall.xpm", id);
	game->img.collect = get_sprite("assets/fruit.xpm", id);
	game->img.score = get_sprite("assets/score.xpm", id);
	game->img.slime_r[0] = get_sprite("assets/sr1.xpm", id);
	game->img.slime_r[1] = get_sprite("assets/sr2.xpm", id);
	game->img.slime_l[0] = get_sprite("assets/sl1.xpm", id);
	game->img.slime_l[1] = get_sprite("assets/sl2.xpm", id);
	game->img.slime_sprite = game->img.slime_l[0];
	i = 0;
	while (i < 4)
	{
		xpm = get_xpm_file("exit", i + 1);
		game->img.exit[i++] = get_sprite(xpm, id);
		free(xpm);
	}
}

static void	init_window(t_game *game)
{
	int		x;
	int		y;

	x = game->map.n_col * SIZE;
	y = game->map.n_row * SIZE;
	game->id = mlx_init();
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
