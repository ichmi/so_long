/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_exit_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 15:04:08 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/27 22:45:20 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_animate(t_game *game, int x, int y)
{
	void	*id;
	void	*window;

	x *= game->size;
	y *= game->size;
	id = game->id;
	window = game->window;
	if (game->end)
		mlx_put_image_to_window(id, window, game->img.exit[3], x, y);
	else
	{
		if (game->timer >= 0 && game->timer < 2)
			mlx_put_image_to_window(id, window, game->img.exit[0], x, y);
		if (game->timer >= 2 && game->timer < 4)
			mlx_put_image_to_window(id, window, game->img.exit[1], x, y);
		if (game->timer >= 4 && game->timer < 6)
			mlx_put_image_to_window(id, window, game->img.exit[2], x, y);
	}
}
