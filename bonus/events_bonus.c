/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:57:34 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/26 20:22:39 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_win_condition(t_game *game)
{
	if (game->fruit == game->total_fruits)
		game->end = 1;
}

static int	is_arrow(int key)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		return (1);
	return (0);
}

int	key_hook(int key, t_game *game)
{
	if (key == 'q' || key == ESC)
		clean_before_exit(game);
	if (ft_strchr("wasd", key) || is_arrow(key))
		move_player(key, game);
	check_win_condition(game);
	return (0);
}

void	init_event_handler(t_game *game)
{
	mlx_loop_hook(game->id, render_map, game);
	mlx_key_hook(game->window, key_hook, game);
	mlx_hook(game->window, 17, 0, clean_before_exit, game);
	mlx_loop(game->id);
}
