/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:00:39 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/21 04:56:59 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_exit(t_game *game, char dir)
{
	if (dir == 'N')
		return (game->map.matrix[game->y - 1][game->x] == 'E');
	if (dir == 'S')
		return (game->map.matrix[game->y + 1][game->x] == 'E');
	if (dir == 'W')
		return (game->map.matrix[game->y][game->x - 1] == 'E');
	if (dir == 'E')
		return (game->map.matrix[game->y][game->x + 1] == 'E');
	return (0);
}

static int	is_valid_move(t_game *game, char dir)
{
	if (!game->end)
	{
		if (dir == 'N')
			return (!ft_strchr("1E", game->map.matrix[game->y - 1][game->x]));
		if (dir == 'S')
			return (!ft_strchr("1E", game->map.matrix[game->y + 1][game->x]));
		if (dir == 'W')
			return (!ft_strchr("1E", game->map.matrix[game->y][game->x - 1]));
		if (dir == 'E')
			return (!ft_strchr("1E", game->map.matrix[game->y][game->x + 1]));
	}
	if (is_exit(game, dir))
		clean_before_exit(game);
	if (dir == 'N')
		return (!ft_strchr("1", game->map.matrix[game->y - 1][game->x]));
	if (dir == 'S')
		return (!ft_strchr("1", game->map.matrix[game->y + 1][game->x]));
	if (dir == 'W')
		return (!ft_strchr("1", game->map.matrix[game->y][game->x - 1]));
	if (dir == 'E')
		return (!ft_strchr("1", game->map.matrix[game->y][game->x + 1]));
	return (0);
}

static void	update_player_coordinates(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.n_row)
	{
		j = -1;
		while (++j < game->map.n_col)
		{
			if (game->map.matrix[i][j] == 'P')
			{
				game->y = i;
				game->x = j;
			}
		}
	}
}

void	move_player(int key, t_game *game)
{
	update_player_coordinates(game);
	if (key == 'w' || key == UP)
		if (is_valid_move(game, 'N'))
			move_north(game);
	if (key == 'a' || key == LEFT)
		if (is_valid_move(game, 'W'))
			move_west(game);
	if (key == 's' || key == DOWN)
		if (is_valid_move(game, 'S'))
			move_south(game);
	if (key == 'd' || key == RIGHT)
		if (is_valid_move(game, 'E'))
			move_east(game);
}
