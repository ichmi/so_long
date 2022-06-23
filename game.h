/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:51:50 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/21 06:21:30 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_img
{
	void	*player_w;
	void	*player_a;
	void	*player_s;
	void	*player_d;
	void	*exit_close;
	void	*exit_open;
	void	*rip;
	void	*counter;
}			t_img;

typedef struct s_sprite
{
	void	*exit_open;
	void	*exit_close_1;
	void	*exit_close_2;
	void	*exit_close_3;
	void	*char_r1;
	void	*char_r2;
	void	*char_r3;
	void	*floor;
	void	*wall;
	void	*collect;
}			t_sprite;

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
	void		*id;
	void		*window;
	t_map		map;
	t_sprite	img;
	int			x;
	int			y;
	int			fruit;
	int			total_fruits;
	int			moves;
	int			end;
	int			dead_player;
	int			loop_tick;
	int			player_moved;
}				t_game;
#endif
