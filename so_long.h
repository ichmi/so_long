/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frosa-ma <frosa-ma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:06:22 by frosa-ma          #+#    #+#             */
/*   Updated: 2022/06/19 15:15:18 by frosa-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "game.h"
# include <stdio.h> // remover

void	init_map(char *filename, t_map *map);
void	validate_map_sides(t_map *map);
void	validate_map_attributes(t_map *map);

# endif
