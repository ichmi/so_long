/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_slime_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 23:30:37 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/27 22:44:41 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	__right_a(t_game *game, int x, int y)
{
	void	*id;
	void	*window;

	x *= game->size;
	y *= game->size;
	id = game->id;
	window = game->window;
	if (game->timer >= 0 && game->timer < 2)
		mlx_put_image_to_window(id, window, game->img.slime_r[0], x, y);
	if (game->timer >= 2 && game->timer < 4)
		mlx_put_image_to_window(id, window, game->img.slime_r[1], x, y);
	if (game->timer >= 4 && game->timer < 6)
		mlx_put_image_to_window(id, window, game->img.slime_r[0], x, y);
	if (game->timer >= 6 && game->timer < 8)
		mlx_put_image_to_window(id, window, game->img.slime_r[1], x, y);
	if (game->timer >= 8 && game->timer < 10)
		mlx_put_image_to_window(id, window, game->img.slime_r[0], x, y);
	if (game->timer >= 10 && game->timer < 12)
		mlx_put_image_to_window(id, window, game->img.slime_r[1], x, y);
	if (game->timer >= 12 && game->timer <= 14)
		mlx_put_image_to_window(id, window, game->img.slime_r[0], x, y);
}

static void	__left_a(t_game *game, int x, int y)
{
	void	*id;
	void	*window;

	x *= game->size;
	y *= game->size;
	id = game->id;
	window = game->window;
	if (game->timer >= 0 && game->timer < 2)
		mlx_put_image_to_window(id, window, game->img.slime_l[0], x, y);
	if (game->timer >= 2 && game->timer < 4)
		mlx_put_image_to_window(id, window, game->img.slime_l[1], x, y);
	if (game->timer >= 4 && game->timer < 6)
		mlx_put_image_to_window(id, window, game->img.slime_l[0], x, y);
	if (game->timer >= 6 && game->timer < 8)
		mlx_put_image_to_window(id, window, game->img.slime_l[1], x, y);
	if (game->timer >= 8 && game->timer < 10)
		mlx_put_image_to_window(id, window, game->img.slime_l[0], x, y);
	if (game->timer >= 10 && game->timer < 12)
		mlx_put_image_to_window(id, window, game->img.slime_l[1], x, y);
	if (game->timer >= 12 && game->timer <= 14)
		mlx_put_image_to_window(id, window, game->img.slime_l[0], x, y);
}

void	slime_animate(t_game *game, int x, int y)
{
	if (game->img.slime_sprite == game->img.slime_r[0])
		__right_a(game, x, y);
	if (game->img.slime_sprite == game->img.slime_l[0])
		__left_a(game, x, y);
}
