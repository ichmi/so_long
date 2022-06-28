/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:06:53 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/28 04:28:36 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_game_objective(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.n_row)
	{
		j = -1;
		while (++j < game->map.n_col)
			if (game->map.matrix[i][j] == 'C')
				game->total_fruits++;
	}
}

void	*get_sprite(char *pathname, t_game *game)
{
	int		width;
	int		height;

	width = game->size;
	height = game->size;
	return (mlx_xpm_file_to_image(game->id, pathname, &width, &height));
}

char	*get_xpm_file(char *filename, t_game *game, int n)
{
	char	*dir;
	char	*s1;
	char	*s2;
	char	*s3;
	char	*i;

	i = ft_itoa(n);
	if (game->size == 32)
		dir = "assets/32/";
	else
		dir = "assets/64/";
	s1 = ft_strjoin(dir, filename);
	s2 = ft_strjoin(s1, i);
	s3 = ft_strjoin(s2, ".xpm");
	free(i);
	free(s1);
	free(s2);
	return (s3);
}

void	init_32px_xpm(t_game *game)
{
	char	*xpm;
	int		i;

	i = 0;
	game->img.floor = get_sprite("assets/32/floor.xpm", game);
	game->img.wall = get_sprite("assets/32/wall.xpm", game);
	game->img.collect = get_sprite("assets/32/fruit.xpm", game);
	game->img.score = get_sprite("assets/32/score.xpm", game);
	game->img.slime_r[0] = get_sprite("assets/32/sr1.xpm", game);
	game->img.slime_r[1] = get_sprite("assets/32/sr2.xpm", game);
	game->img.slime_l[0] = get_sprite("assets/32/sl1.xpm", game);
	game->img.slime_l[1] = get_sprite("assets/32/sl2.xpm", game);
	game->img.slime_sprite = game->img.slime_l[0];
	while (i < 4)
	{
		xpm = get_xpm_file("exit", game, i + 1);
		game->img.exit[i++] = get_sprite(xpm, game);
		free(xpm);
	}
}

void	init_64px_xpm(t_game *game)
{
	char	*xpm;
	int		i;

	i = 0;
	game->img.floor = get_sprite("assets/64/floor.xpm", game);
	game->img.wall = get_sprite("assets/64/wall.xpm", game);
	game->img.collect = get_sprite("assets/64/fruit.xpm", game);
	game->img.score = get_sprite("assets/64/score.xpm", game);
	game->img.slime_r[0] = get_sprite("assets/64/sr1.xpm", game);
	game->img.slime_r[1] = get_sprite("assets/64/sr2.xpm", game);
	game->img.slime_l[0] = get_sprite("assets/64/sl1.xpm", game);
	game->img.slime_l[1] = get_sprite("assets/64/sl2.xpm", game);
	game->img.slime_sprite = game->img.slime_l[0];
	while (i < 4)
	{
		xpm = get_xpm_file("exit", game, i + 1);
		game->img.exit[i++] = get_sprite(xpm, game);
		free(xpm);
	}
}
