/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:57:56 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/26 23:29:38 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	__right_a(t_game *game, int x, int y)
{
	void	*id;
	void	*window;

	x *= SIZE;
	y *= SIZE;
	id = game->id;
	window = game->window;
	if (game->timer >= 0 && game->timer < 2)
		mlx_put_image_to_window(id, window, game->img.char_r[0], x, y);
	if (game->timer >= 2 && game->timer < 4)
		mlx_put_image_to_window(id, window, game->img.char_r[1], x, y);
	if (game->timer >= 4 && game->timer < 6)
		mlx_put_image_to_window(id, window, game->img.char_r[2], x, y);
	if (game->timer >= 6 && game->timer < 8)
		mlx_put_image_to_window(id, window, game->img.char_r[3], x, y);
	if (game->timer >= 8 && game->timer < 10)
		mlx_put_image_to_window(id, window, game->img.char_r[4], x, y);
	if (game->timer >= 10 && game->timer < 12)
		mlx_put_image_to_window(id, window, game->img.char_r[5], x, y);
	if (game->timer >= 12 && game->timer <= 14)
		mlx_put_image_to_window(id, window, game->img.char_r[6], x, y);
}

static void	__left_a(t_game *game, int x, int y)
{
	void	*id;
	void	*window;

	x *= SIZE;
	y *= SIZE;
	id = game->id;
	window = game->window;
	if (game->timer >= 0 && game->timer < 2)
		mlx_put_image_to_window(id, window, game->img.char_l[0], x, y);
	if (game->timer >= 2 && game->timer < 4)
		mlx_put_image_to_window(id, window, game->img.char_l[1], x, y);
	if (game->timer >= 4 && game->timer < 6)
		mlx_put_image_to_window(id, window, game->img.char_l[2], x, y);
	if (game->timer >= 6 && game->timer < 8)
		mlx_put_image_to_window(id, window, game->img.char_l[3], x, y);
	if (game->timer >= 8 && game->timer < 10)
		mlx_put_image_to_window(id, window, game->img.char_l[4], x, y);
	if (game->timer >= 10 && game->timer < 12)
		mlx_put_image_to_window(id, window, game->img.char_l[5], x, y);
	if (game->timer >= 12 && game->timer <= 14)
		mlx_put_image_to_window(id, window, game->img.char_l[6], x, y);
}

static void	__bottom_a(t_game *game, int x, int y)
{
	void	*id;
	void	*window;

	x *= SIZE;
	y *= SIZE;
	id = game->id;
	window = game->window;
	if (game->timer >= 0 && game->timer < 2)
		mlx_put_image_to_window(id, window, game->img.char_b[0], x, y);
	if (game->timer >= 2 && game->timer < 4)
		mlx_put_image_to_window(id, window, game->img.char_b[1], x, y);
	if (game->timer >= 4 && game->timer < 6)
		mlx_put_image_to_window(id, window, game->img.char_b[2], x, y);
	if (game->timer >= 6 && game->timer < 8)
		mlx_put_image_to_window(id, window, game->img.char_b[3], x, y);
	if (game->timer >= 8 && game->timer < 10)
		mlx_put_image_to_window(id, window, game->img.char_b[4], x, y);
	if (game->timer >= 10 && game->timer < 12)
		mlx_put_image_to_window(id, window, game->img.char_b[5], x, y);
	if (game->timer >= 12 && game->timer <= 14)
		mlx_put_image_to_window(id, window, game->img.char_b[6], x, y);
}

static void	__top_a(t_game *game, int x, int y)
{
	void	*id;
	void	*window;

	x *= SIZE;
	y *= SIZE;
	id = game->id;
	window = game->window;
	if (game->timer >= 0 && game->timer < 2)
		mlx_put_image_to_window(id, window, game->img.char_t[0], x, y);
	if (game->timer >= 2 && game->timer < 4)
		mlx_put_image_to_window(id, window, game->img.char_t[1], x, y);
	if (game->timer >= 4 && game->timer < 6)
		mlx_put_image_to_window(id, window, game->img.char_t[2], x, y);
	if (game->timer >= 6 && game->timer < 8)
		mlx_put_image_to_window(id, window, game->img.char_t[3], x, y);
	if (game->timer >= 8 && game->timer < 10)
		mlx_put_image_to_window(id, window, game->img.char_t[4], x, y);
	if (game->timer >= 10 && game->timer < 12)
		mlx_put_image_to_window(id, window, game->img.char_t[5], x, y);
}

void	player_animate(t_game *game, int x, int y)
{
	if (game->img.fox_sprite == game->img.char_r[0])
		__right_a(game, x, y);
	if (game->img.fox_sprite == game->img.char_l[0])
		__left_a(game, x, y);
	if (game->img.fox_sprite == game->img.char_t[0])
		__top_a(game, x, y);
	if (game->img.fox_sprite == game->img.char_b[0])
		__bottom_a(game, x, y);
}
