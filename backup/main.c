/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <git.ichmi@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:46:41 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/18 16:47:57 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include <time.h>


typedef struct	p_param
{
	int	x;
	int	y;
	void	*mlx;
	void	*win;
}				t_param;


void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
}

int		key_press(int keycode, t_param *param)
{
	void	*img;
	int	w;
	int	h;
	
	if (keycode == 'w')
		param->y++;
	else if (keycode == 's')
		param->y--;
	else if (keycode == 'd')
		param->x++;
	else if (keycode == 'a')
		param->x--;
	else if (keycode == XK_Escape)
		exit(0);
	printf("(%d, %d)\n", param->x, param->y);
	return (0);
}


int	render(t_param *param)
{
	void	*img;
	int		w;
	int		h;

	img = mlx_xpm_file_to_image(param->mlx, "./sprites/s1.xpm", &w, &h);
	mlx_put_image_to_window(param->mlx, param->win, img, 0, 0);
	usleep(120000);

	img = mlx_xpm_file_to_image(param->mlx, "./sprites/s2.xpm", &w, &h);
	mlx_put_image_to_window(param->mlx, param->win, img, 0, 0);
	usleep(120000);

	img = mlx_xpm_file_to_image(param->mlx, "./sprites/s3.xpm", &w, &h);
	mlx_put_image_to_window(param->mlx, param->win, img, 0, 0);
	usleep(120000);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	void	*img;
	int		w;
	int		h;
	t_param	param;

	param_init(&param);
	param.mlx = mlx_init();

	param.win = mlx_new_window(param.mlx, 13 * 64, 6 * 64, "so_long");
	img = mlx_xpm_file_to_image(param.mlx, "./sprites/floor.xpm", &w, &h);
	for (int i = 0; i < 13; ++i)
		for (int j = 0; j < 6; ++j)
			mlx_put_image_to_window(param.mlx, param.win, img, i * 64, j * 64);

	mlx_key_hook(param.win, &key_press, &param);
	mlx_loop_hook(param.mlx, render, &param);
	mlx_loop(param.mlx);
}
