/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:42:37 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/05 10:35:55 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_to_empty(t_game *game, t_tile *tile)
{
	tile->type = PLAYER;
	if (game->player.tile->type != EXIT)
		game->player.tile->type = EMPTY;
	game->player.tile = tile;
}

void	pick_to_collect(t_game *game, t_tile *tile)
{
	tile->type = EMPTY;
	game->collects--;
	action_anima(&game->player);
}

void	move_to_exit(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window, game->white_panel, 0, 0);
	player_remove(game);
	game->collects = -1;
}

void	move_to_enemy(t_game *game)
{
	player_remove(game);
	mlx_put_image_to_window(game->mlx, game->window, game->red_panel, 0, 0);
}
