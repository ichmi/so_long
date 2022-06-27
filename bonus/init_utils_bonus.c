/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 20:06:53 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/25 20:09:41 by frosa-ma         ###   ########.fr       */
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

char	*get_xpm_file(char *filename, int n)
{
	char	*dir;
	char	*s1;
	char	*s2;
	char	*s3;
	char	*i;

	i = ft_itoa(n);
	dir = "assets/";
	s1 = ft_strjoin(dir, filename);
	s2 = ft_strjoin(s1, i);
	s3 = ft_strjoin(s2, ".xpm");
	free(i);
	free(s1);
	free(s2);
	return (s3);
}
