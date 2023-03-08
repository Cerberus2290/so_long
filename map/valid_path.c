/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:00:29 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/08 09:04:04 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_bool	find_path(t_tile *tile, t_bool c_found, t_bool e_found)
{
	if (tile == NULL || tile->type == WALL || tile->type == ENEMY)
		return (FALSE);
	if (tile->type == EXIT && c_found)
	{
		e_found = TRUE;
		return (TRUE);
	}
	if (tile->type == COLLECTABLE)
		c_found = TRUE;
	tile->type = WALL;
	if (find_path(tile->up, c_found, e_found))
		return (TRUE);
	if (find_path(tile->down, c_found, e_found))
		return (TRUE);
	if (find_path(tile->left, c_found, e_found))
		return (TRUE);
	if (find_path(tile->right, c_found, e_found))
		return (TRUE);
	tile->type = EMPTY;
	return (FALSE);
}

t_bool	find_valid_path(t_game *game)
{
	t_bool	c_found;
	t_bool	e_found;

	c_found = FALSE;
	e_found = FALSE;
	return (find_path(game->player.tile, c_found, e_found));
}
