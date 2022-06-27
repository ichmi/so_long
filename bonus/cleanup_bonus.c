/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 03:00:50 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/26 23:40:32 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	free_images(t_game *game)
{
	void	*id;
	int		i;

	id = game->id;
	i = 7;
	while (i)
		mlx_destroy_image(id, game->img.char_r[--i]);
	while (i < 7)
		mlx_destroy_image(id, game->img.char_l[i++]);
	while (i)
		mlx_destroy_image(id, game->img.char_b[--i]);
	while (i < 6)
		mlx_destroy_image(id, game->img.char_t[i++]);
	i = 0;
	while (i < 4)
		mlx_destroy_image(id, game->img.exit[i++]);
	mlx_destroy_image(id, game->img.floor);
	mlx_destroy_image(id, game->img.wall);
	mlx_destroy_image(id, game->img.collect);
	mlx_destroy_image(id, game->img.score);
	mlx_destroy_image(id, game->img.slime_r[0]);
	mlx_destroy_image(id, game->img.slime_r[1]);
	mlx_destroy_image(id, game->img.slime_l[0]);
	mlx_destroy_image(id, game->img.slime_l[1]);
}

static void	free_window(t_game *game)
{
	mlx_clear_window(game->id, game->window);
	mlx_destroy_window(game->id, game->window);
	mlx_destroy_display(game->id);
	free(game->id);
}

static void	free_matrix(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.n_row)
		free(game->map.matrix[i++]);
	free(game->map.matrix);
}

int	clean_before_exit(t_game *game)
{
	free_matrix(game);
	free_images(game);
	free_window(game);
	exit(0);
	return (0);
}
