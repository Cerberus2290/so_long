/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:56:53 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/13 11:36:55 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../basic.h"
# include "../so_long.h"
# include <time.h>

int		valid_file(int argc, char *file);
char	**read_map(char *file);
int		valid_map(char **map);
t_bool	valid_path(t_game *game);

/* struct to check map data */
typedef struct s_mapdata
{
	t_vector	size;
	t_vector	point;
	t_bool		b_player;
	t_bool		b_exit;
	t_bool		b_collect;
}	t_mapdata;

void	add_enemy(t_game *game, t_enemytypes type, t_tile *tile);

#endif