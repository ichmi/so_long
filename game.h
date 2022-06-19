/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:51:50 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/19 05:50:37 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct	s_img
{
	void	*floor;
	void	*wall;
	void	*collect;
	void	*player_w;
	void	*player_a;
	void	*player_s;
	void	*player_d;
	void	*exit_close;
	void	*exit_open;
	void	*rip;
	void	*counter;
}				t_img;


typedef struct	s_map
{
	char	**matrix;
	int		n_row;
	int		n_col;
	int		p;
	int		c;
	int		e;
}				t_map;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	char	**map;
	int		map_h;
	int		map_w;
	int		player_x;
	int		player_y;
	int		collected;
	int		moves;
	int		end_game;
	int		dead_player;
	int		loop_tick;
	int		player_moved;
}				t_data;

# endif
