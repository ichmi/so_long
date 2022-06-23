/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 22:20:14 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/21 04:28:11 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_north(t_game *game)
{
	if (game->map.matrix[game->y - 1][game->x] == 'C')
		game->fruit++;
	game->map.matrix[game->y][game->x] = '0';
	game->map.matrix[game->y - 1][game->x] = 'P';
	game->moves++;
}

void	move_south(t_game *game)
{
	if (game->map.matrix[game->y + 1][game->x] == 'C')
		game->fruit++;
	game->map.matrix[game->y][game->x] = '0';
	game->map.matrix[game->y + 1][game->x] = 'P';
	game->moves++;
}

void	move_west(t_game *game)
{
	if (game->map.matrix[game->y][game->x - 1] == 'C')
		game->fruit++;
	game->map.matrix[game->y][game->x] = '0';
	game->map.matrix[game->y][game->x - 1] = 'P';
	game->moves++;
}

void	move_east(t_game *game)
{
	if (game->map.matrix[game->y][game->x + 1] == 'C')
		game->fruit++;
	game->map.matrix[game->y][game->x] = '0';
	game->map.matrix[game->y][game->x + 1] = 'P';
	game->moves++;
}
