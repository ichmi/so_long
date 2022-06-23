/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:50:09 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/22 20:23:29 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_game_objective(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.n_row)
	{
		j = -1;
		while (++j < game->map.n_col)
			if (game->map.matrix[i][j] == 'C')
				game->total_fruits++;
	}
}

static void	*get_sprite(char *pathname, void *id)
{
	int		width;
	int		height;

	width = SIZE;
	height = SIZE;
	return (mlx_xpm_file_to_image(id, pathname, &width, &height));
}

static void	init_sprites(t_game *game)
{
	void	*id;

	id = game->id;
	game->img.floor = get_sprite("assets/floor.xpm", id);
	game->img.wall = get_sprite("assets/wall.xpm", id);
	game->img.collect = get_sprite("assets/fruit.xpm", id);
	game->img.char_r1 = get_sprite("assets/char_r1.xpm", id);
	game->img.exit_open = get_sprite("assets/exit4.xpm", id);
}

static void	init_window(t_game *game)
{
	int		x;
	int		y;

	x = game->map.n_col * SIZE;
	y = game->map.n_row * SIZE;
	game->id = mlx_init();
	game->window = mlx_new_window(game->id, x, y, "so_long (frosa-ma)");
}

void	init_game(t_game *game)
{
	init_window(game);
	ft_printf("\rMoves: %d", game->moves);
	init_sprites(game);
	set_game_objective(game);
	mlx_loop_hook(game->id, loop_hook, game);
	mlx_key_hook(game->window, key_hook, game);
	mlx_hook(game->window, 17, 0, clean_before_exit, game);
	mlx_loop(game->id);
}
