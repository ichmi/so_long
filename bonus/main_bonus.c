/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:20:18 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/27 22:33:05 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_game_attr(t_game *game)
{
	game->x = 0;
	game->y = 0;
	game->end = 0;
	game->fruit = 0;
	game->total_fruits = 0;
	game->moves = 0;
	game->map.p = 0;
	game->map.c = 0;
	game->map.e = 0;
	game->map.n_row = 0;
	game->map.n_col = 0;
	game->map.found_slime = 0;
	game->timer = 0;
	game->size = 64;
}

static int	is_valid_file_extension(char *s)
{
	size_t	offset;

	offset = ft_strlen(s) - 4;
	if (ft_strncmp(".ber", s + offset, 5) == 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		ft_printf("Error\nInvalid number of arguments\n");
		exit(1);
		return (1);
	}
	if (!is_valid_file_extension(av[1]))
	{
		ft_printf("Error\nInvalid file extension\n");
		exit(1);
		return (1);
	}
	init_game_attr(&game);
	init_map(av[1], &game);
	init_game(&game);
	return (0);
}
