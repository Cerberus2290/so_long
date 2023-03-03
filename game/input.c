/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:15:27 by tstrassb          #+#    #+#             */
/*   Updated: 2023/02/26 12:34:11 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_enemies(t_game *game);
void	move_to_empty(t_game *game, t_tile *tile);
void	move_to_exit(t_game *game, t_tile *tile);
void	pick_to_collect(t_game *game, t_tile *tile);
void	move_to_enemy(t_game *game, t_tile *tile);

/* start action animation for player */
void	action_anima(t_player *player)
{
	player->framecount = 0;
	player->current_img = player->action_img;
}

/* execute [tile] specific action if player is on that tile */
t_bool	move_to(t_game *game, t_tile *tile)
{
	if (tile->type == EMPTY)
		move_to_empty(game, tile);
	else if (tile->type == COLLECTABLE)
		pick_to_collect(game, tile);
	else if (tile->type == EXIT && game->collects <= 0)
		move_to_exit(game, tile);
	else if (tile->type == ENEMY || tile->type == FOLLOWER)
	{
		move_to_enemy(game, tile);
		return (FALSE);
	}
	else
		return (FALSE);
	move_enemies(game);
	return (TRUE);
}

/* input handling - called each time a key is pressed */
int	input(int key, t_game *game)
{
	t_bool	move;

	if (key == QUIT)
		end_program(game);
	else if (key == RESET)
		return (reset(game));
	if (game->player.tile == NULL)
		return (0);
	if (key == KEY_UP)
		move = move_to(game, game->player.tile->up);
	else if (key == KEY_DOWN)
		move = move_to(game, game->player.tile->down);
	else if (key == KEY_LEFT)
		move = move_to(game, game->player.tile->left);
	else if (key == KEY_RIGHT)
		move = move_to(game, game->player.tile->right);
	else
		return (0);
	if (move)
		ft_printf("Moves -> %02d\n", ++game->moves);
	return (1);
}
