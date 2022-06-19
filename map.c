/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:02:07 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/19 15:30:05 by frosa-ma         ###   ########.fr       */
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
		printf("Error\nfloating point exception, empty map file\n");
		return ;
	}
	map->n_col /= map->n_row;
	if (map->n_col < 3 || map->n_row < 3 || map->n_col == map->n_row)
	{
		printf("Error\ninvalid map dimension\n");
		return ;
	}
}

void	init_matrix(char *filename, t_map *map)
{
	char	*buffer;
	char	*row;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ;
	buffer = ft_strdup("");
	while (1)
	{
		row = ft_gnl(fd);
		if (!row)
			break ;
		if (ft_strncmp(row, "\n", 2) == 0)
		{
			printf("Error\ninvalid map, empty line(s) on map\n"); // Will segfault other fn execution later on
			free(buffer);
			return ;
		}
		buffer = ft_strjoins(buffer, row);
	}
	map->matrix = ft_split(buffer, '\n');
	free(buffer);
	close(fd);
}

void	init_map(char *filename, t_map *map)
{
	init_matrix(filename, map);
	get_map_dimension(map);
	validate_map_attributes(map);
	validate_map_sides(map);
}
