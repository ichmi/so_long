/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 03:00:50 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/27 00:31:58 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_images(t_game *game)
{
	void	*id;

	id = game->id;
	mlx_destroy_image(id, game->img.floor);
	mlx_destroy_image(id, game->img.wall);
	mlx_destroy_image(id, game->img.collect);
	mlx_destroy_image(id, game->img.char_r1);
	mlx_destroy_image(id, game->img.exit_open);
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
	{
		free(game->map.matrix[i]);
		i++;
	}
	free(game->map.matrix);
}

int	clean_before_exit(t_game *game)
{
	free_matrix(game);
	free_images(game);
	free_window(game);
	ft_printf("\n");
	exit(0);
	return (0);
}
