/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_kill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:30:53 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/05 10:31:49 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_kill(t_game *game, t_vector pos)
{
	game->player.tile = NULL;
	effect_anima(&game->effect, pos);
	mlx_put_image_to_window(game->mlx, game->window, game->red_panel, 0, 0);
}

void	player_remove(t_game *game)
{
	game->player.tile->type = EMPTY;
	game->player.tile = NULL;
}
