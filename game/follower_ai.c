/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follower_ai.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:22:17 by tstrassb          #+#    #+#             */
/*   Updated: 2023/02/28 19:09:48 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_bool	move_horiz(t_enemies *enemy, t_game *game);
t_bool	move_verti(t_enemies *enemy, t_game *game);

int	define_dir(int value)
{
	if (value < 0)
		return (1);
	else if (value > 0)
		return (0);
	return (-1);
}

void	follow_player(t_enemies *enemy, t_game *game)
{
	int	dist_x;
	int	dist_y;

	if (game->player.tile == NULL)
		return ;
	dist_x = enemy->tile->position.x - game->player.tile->position.x;
	dist_y = enemy->tile->position.y - game->player.tile->position.y;
	if (dist_x > dist_y)
	{
		enemy->dir = define_dir(dist_x);
		if (!move_horiz(enemy, game) || enemy->dir == -1)
		{
			enemy->dir = define_dir(dist_y);
			move_verti(enemy, game);
		}
	}
	else
	{
		enemy->dir = define_dir(dist_y);
		if (!move_verti(enemy, game) || enemy->dir == -1)
		{
			enemy->dir = define_dir(dist_x);
			move_horiz(enemy, game);
		}
	}
}
