/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:57:34 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/27 00:36:39 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	ft_printf("\r\033[0;31mMoves:\033[0;33m %d\033[0m", game->moves);
	check_win_condition(game);
	return (0);
}

int	loop_hook(t_game *game)
{
	render_map(game);
	return (0);
}
