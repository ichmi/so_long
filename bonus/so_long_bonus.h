/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:06:22 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/28 04:58:38 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <time.h>
# include <X11/X.h>
# include <X11/keysym.h>

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
	void	*fox_sprite;
	void	*slime_sprite;
	void	*char_r[7];
	void	*char_l[7];
	void	*char_b[7];
	void	*char_t[6];
	void	*slime_r[2];
	void	*slime_l[2];
	void	*floor;
	void	*wall;
	void	*collect;
	void	*score;
	void	*exit[4];
}			t_img;

typedef struct s_map
{
	char	**matrix;
	int		n_row;
	int		n_col;
	int		p;
	int		c;
	int		e;
	int		found_slime;
}			t_map;

typedef struct s_game
{
	void	*id;
	void	*window;
	t_map	map;
	t_img	img;
	int		x;
	int		y;
	int		sx;
	int		sy;
	int		fruit;
	int		total_fruits;
	int		moves;
	int		end;
	int		timer;
	int		size;
}			t_game;

void	init_map(char *filename, t_game *game);
void	validate_map_sides(t_map *map);
void	validate_map_attributes(t_map *map);
void	init_game(t_game *game);
int		render_map(t_game *game);
int		key_hook(int key, t_game *game);
void	move_player(int key, t_game *game);
void	move_north(t_game *game);
void	move_south(t_game *game);
void	move_west(t_game *game);
void	move_east(t_game *game);
int		clean_before_exit(t_game *game);
char	*ft_alt_gnl(int fd);
void	player_animate(t_game *game, int x, int y);
void	exit_animate(t_game *game, int x, int y);
void	init_event_handler(t_game *game);
void	set_game_objective(t_game *game);
void	*get_sprite(char *pathname, t_game *game);
char	*get_xpm_file(char *filename, t_game *game, int n);
int		validate_slime_next_move(int n, t_game *game);
int		is_valid_move(t_game *game, char dir);
void	slime_animate(t_game *game, int x, int y);
void	init_32px_xpm(t_game *game);
void	init_64px_xpm(t_game *game);

#endif
