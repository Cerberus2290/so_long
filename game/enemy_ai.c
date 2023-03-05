/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_ai.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:16:26 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/05 10:10:40 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	follow_player(t_enemies *enemy, t_game *game);

/* changes enemy type */
void	move_enemy_to(t_enemies *enemy, t_tile *tile)
{
	enemy->tile->type = EMPTY;
	if (enemy->type == FOLLOW_ENEMY)
		tile->type = FOLLOWER;
	else
		tile->type = ENEMY;
	enemy->tile = tile;
}

/* changes [enemy] dir to 1, if 0
if 1 change to 0 */
t_bool	change_dir(t_enemies *enemy)
{
	if (enemy->dir == 0)
		enemy->dir = 1;
	else
		enemy->dir = 0;
	return (FALSE);
}

/* moves [enemy] left or right based on its drection */
t_bool	move_horiz(t_enemies *enemy, t_game *game)
{
	if (enemy->dir == 0)
	{
		if (enemy->tile->left->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->left);
		else if (enemy->tile->left->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->left);
			player_kill(game, enemy->tile->position);
		}
		else
			return (change_dir(enemy));
	}
	else if (enemy->dir == 1)
	{
		if (enemy->tile->right->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->right);
		else if (enemy->tile->right->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->right);
			player_kill(game, enemy->tile->position);
		}
		else
			return (change_dir(enemy));
	}
	return (TRUE);
}

/* moves [enemy] up or down based on its drection */
t_bool	move_verti(t_enemies *enemy, t_game *game)
{
	if (enemy->dir == 0)
	{
		if (enemy->tile->up->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->up);
		else if (enemy->tile->up->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->up);
			player_kill(game, enemy->tile->position);
		}
		else
			return (change_dir(enemy));
	}
	else if (enemy->dir == 1)
	{
		if (enemy->tile->down->type == EMPTY)
			move_enemy_to(enemy, enemy->tile->down);
		else if (enemy->tile->down->type == PLAYER)
		{
			move_enemy_to(enemy, enemy->tile->down);
			player_kill(game, enemy->tile->position);
		}
		else
			return (change_dir(enemy));
	}
	return (TRUE);
}

/* goes through enemies struct and moves all according to their type */
void	move_enemies(t_game *game)
{
	t_enemies	*current;

	if (game->enemy_list == NULL)
		return ;
	current = game->enemy_list;
	while (TRUE)
	{
		if (current->type == HORIZONTAL_ENEMY)
			move_horiz(current, game);
		else if (current->type == VERTICAL_ENEMY)
			move_verti(current, game);
		else if (current->type == FOLLOW_ENEMY)
			follow_player(current, game);
		if (current->next == NULL)
			break ;
		current = current->next;
	}
}
