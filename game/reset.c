/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:47:08 by tstrassb          #+#    #+#             */
/*   Updated: 2023/02/28 13:59:36 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	reset_enemies(t_enemies *enemy)
{
	if (enemy == NULL)
		return ;
	while (TRUE)
	{
		enemy->tile = enemy->og_tile;
		enemy->dir = 0;
		if (enemy->next == NULL)
			break ;
		enemy = enemy->next;
	}
}

/* resets the game to original state */
int	reset(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->tilemap[y] != NULL)
	{
		x = 0;
		while (game->tilemap[y][x].type != 0)
		{
			game->tilemap[y][x].type = game->tilemap[y][x].og_type;
			if (game->tilemap[y][x].type == PLAYER)
				game->player.tile = &game->tilemap[y][x];
			x++;
		}
		y++;
	}
	reset_enemies(game->enemy_list);
	game->moves = 0;
	game->collects = game->og_collects;
	mlx_put_image_to_window(game->mlx, game->window, game->white_panel, 0, 0);
	return (0);
}
