/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:00:29 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/13 11:45:09 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_bool	find_path(t_tile *tile, t_bool c_found,
		t_bool e_found, time_t start_time)
{
	if (difftime(time(NULL), start_time) >= 5.0)
		return (FALSE);
	if (tile == NULL || tile->type == WALL || tile->type == ENEMY
		|| tile->type == FOLLOWER || tile->type == VALID)
		return (FALSE);
	if (tile->type == COLLECTABLE)
		c_found = TRUE;
	if (tile->type == EXIT && c_found)
	{
		e_found = TRUE;
		return (TRUE);
	}
	tile->type = VALID;
	if (difftime(time(NULL), start_time) >= 5.0)
		return (FALSE);
	if (find_path(tile->up, c_found, e_found, start_time))
		return (TRUE);
	if (find_path(tile->down, c_found, e_found, start_time))
		return (TRUE);
	if (find_path(tile->left, c_found, e_found, start_time))
		return (TRUE);
	if (find_path(tile->right, c_found, e_found, start_time))
		return (TRUE);
	tile->type = EMPTY;
	return (FALSE);
}

t_bool	valid_path(t_game *game)
{
	t_bool	c_found;
	t_bool	e_found;
	time_t	start_time;

	c_found = FALSE;
	e_found = FALSE;
	start_time = time(NULL);
	return (find_path(game->player.tile, c_found, e_found, start_time));
}
