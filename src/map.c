/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:02:07 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/28 04:44:36 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_dimension(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->matrix[i])
	{
		j = 0;
		while (map->matrix[i][j++])
			map->n_col++;
		i++;
	}
	map->n_row = i;
	if (!map->n_row)
	{
		ft_printf("Error\nEmpty map file\n");
		ft_free_matrix(map->matrix);
		exit(1);
	}
	map->n_col /= map->n_row;
	if (map->n_col < 3 || map->n_row < 3 || map->n_col == map->n_row)
	{
		ft_printf("Error\nInvalid map dimension\n");
		ft_free_matrix(map->matrix);
		exit(1);
	}
}

static int	is_empty_line(char *row, char *buffer, int fd)
{
	if (ft_strncmp(row, "\n", 2) == 0)
	{
		ft_printf("Error\nInvalid map. Found a empty line on map\n");
		free(row);
		free(buffer);
		close(fd);
		return (1);
	}
	return (0);
}

static int	get_fd(char *filename, char *buffer)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free(buffer);
		ft_printf("Error\nFile \"%s\" doesnt exist\n", filename);
		exit(1);
	}
	return (fd);
}

void	init_matrix(char *filename, char *buffer, t_game *game)
{
	char	*pb;
	char	*row;
	int		fd;

	fd = get_fd(filename, buffer);
	while (1)
	{
		row = ft_alt_gnl(fd);
		if (!row)
		{
			free(row);
			break ;
		}
		if (is_empty_line(row, buffer, fd))
			exit(1);
		pb = buffer;
		buffer = ft_strjoin(buffer, row);
		free(row);
		free(pb);
	}
	game->map.matrix = ft_split(buffer, '\n');
	free(buffer);
	close(fd);
}

void	init_map(char *filename, t_game *game)
{
	char	*buffer;

	buffer = ft_strdup("");
	init_matrix(filename, buffer, game);
	get_map_dimension(&game->map);
	validate_map_attributes(&game->map);
	validate_map_sides(&game->map);
}
