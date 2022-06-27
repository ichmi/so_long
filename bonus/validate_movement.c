/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_movement.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 23:38:00 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/26 23:59:53 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	is_exit_or_slime(t_game *game, char dir, int slime_only)
{
	if (slime_only)
	{
		if (dir == 'N')
			return (game->map.matrix[game->y - 1][game->x] == 'S');
		if (dir == 'S')
			return (game->map.matrix[game->y + 1][game->x] == 'S');
		if (dir == 'W')
			return (game->map.matrix[game->y][game->x - 1] == 'S');
		if (dir == 'E')
			return (game->map.matrix[game->y][game->x + 1] == 'S');
	}
	if (dir == 'N')
		return (!!ft_strchr("ES", game->map.matrix[game->y - 1][game->x]));
	if (dir == 'S')
		return (!!ft_strchr("ES", game->map.matrix[game->y + 1][game->x]));
	if (dir == 'W')
		return (!!ft_strchr("ES", game->map.matrix[game->y][game->x - 1]));
	if (dir == 'E')
		return (!!ft_strchr("ES", game->map.matrix[game->y][game->x + 1]));
	return (0);
}

int	is_valid_move(t_game *game, char dir)
{
	if (!game->end)
	{
		if (is_exit_or_slime(game, dir, 1))
			clean_before_exit(game);
		if (dir == 'N')
			return (!ft_strchr("1E", game->map.matrix[game->y - 1][game->x]));
		if (dir == 'S')
			return (!ft_strchr("1E", game->map.matrix[game->y + 1][game->x]));
		if (dir == 'W')
			return (!ft_strchr("1E", game->map.matrix[game->y][game->x - 1]));
		if (dir == 'E')
			return (!ft_strchr("1E", game->map.matrix[game->y][game->x + 1]));
	}
	if (is_exit_or_slime(game, dir, 0))
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

int	validate_slime_next_move(int n, t_game *game)
{
	if (n == 1)
		return (!ft_strchr("1ESC", game->map.matrix[game->sy - 1][game->sx]));
	if (n == 2)
		return (!ft_strchr("1ESC", game->map.matrix[game->sy + 1][game->sx]));
	if (n == 3)
		return (!ft_strchr("1ESC", game->map.matrix[game->sy][game->sx - 1]));
	if (n == 4)
		return (!ft_strchr("1ESC", game->map.matrix[game->sy][game->sx + 1]));
	return (0);
}
