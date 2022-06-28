/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:06:22 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/28 17:48:50 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

enum	e_alter
{
	ESC = 65307,
	LEFT = 65361,
	UP,
	RIGHT,
	DOWN
};

typedef struct s_img
{
	void	*exit_open;
	void	*r1;
	void	*floor;
	void	*wall;
	void	*collect;
}			t_img;

typedef struct s_map
{
	char	**matrix;
	int		n_row;
	int		n_col;
	int		p;
	int		c;
	int		e;
}			t_map;

typedef struct s_game
{
	void	*id;
	void	*window;
	t_map	map;
	t_img	img;
	int		x;
	int		y;
	int		fruit;
	int		total_fruits;
	int		moves;
	int		end;
	int		size;
}			t_game;

void	init_map(char *filename, t_game *game);
void	validate_map_sides(t_map *map);
void	validate_map_attributes(t_map *map);
void	init_game(t_game *game);
int		loop_hook(t_game *game);
void	render_map(t_game *game);
int		key_hook(int key, t_game *game);
void	move_player(int key, t_game *game);
void	move_north(t_game *game);
void	move_south(t_game *game);
void	move_west(t_game *game);
void	move_east(t_game *game);
int		clean_before_exit(t_game *game);
char	*ft_alt_gnl(int fd);

#endif
