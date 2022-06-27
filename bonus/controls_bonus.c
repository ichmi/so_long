/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:00:39 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/27 00:08:25 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	get_next_slime_direction(void)
{
	int	lower;
	int	higher;

	lower = 1;
	higher = 4;
	srand(time(NULL));
	return ((rand() % (higher - lower + 1)) + lower);
}

static void	move_slime(t_game *game)
{
	int	n;

	n = get_next_slime_direction();
	if (validate_slime_next_move(n, game))
	{
		game->map.matrix[game->sy][game->sx] = '0';
		if (n == 1)
			game->map.matrix[game->sy - 1][game->sx] = 'S';
		if (n == 2)
			game->map.matrix[game->sy + 1][game->sx] = 'S';
		if (n == 3)
		{
			game->img.slime_sprite = game->img.slime_l[0];
			game->map.matrix[game->sy][game->sx - 1] = 'S';
		}
		if (n == 4)
		{
			game->img.slime_sprite = game->img.slime_r[0];
			game->map.matrix[game->sy][game->sx + 1] = 'S';
		}
	}
	if (game->map.matrix[game->y][game->x] == 'S')
		clean_before_exit(game);
}

static void	update_player_slime_coordinates(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.n_row)
	{
		j = -1;
		while (++j < game->map.n_col)
		{
			if (game->map.matrix[i][j] == 'S')
			{
				game->sy = i;
				game->sx = j;
			}
			else if (game->map.matrix[i][j] == 'P')
			{
				game->y = i;
				game->x = j;
			}
		}
	}
}

static void	check_slime_presence(t_game *game)
{
	update_player_slime_coordinates(game);
	if (game->map.found_slime)
		move_slime(game);
}

void	move_player(int key, t_game *game)
{
	check_slime_presence(game);
	if (key == 'w' || key == UP)
	{
		game->img.fox_sprite = game->img.char_t[0];
		if (is_valid_move(game, 'N'))
			move_north(game);
	}
	if (key == 'a' || key == LEFT)
	{
		game->img.fox_sprite = game->img.char_l[0];
		if (is_valid_move(game, 'W'))
			move_west(game);
	}
	if (key == 's' || key == DOWN)
	{
		game->img.fox_sprite = game->img.char_b[0];
		if (is_valid_move(game, 'S'))
			move_south(game);
	}
	if (key == 'd' || key == RIGHT)
	{
		game->img.fox_sprite = game->img.char_r[0];
		if (is_valid_move(game, 'E'))
			move_east(game);
	}
}
