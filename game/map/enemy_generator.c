/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:35:02 by tstrassb          #+#    #+#             */
/*   Updated: 2023/02/26 10:52:07 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/* places enemies with [type] and [tile] using memory allocation */
t_enemies	*new_enemy(t_enemytypes type, t_tile *tile)
{
	t_enemies	*enemy;

	enemy = ft_calloc(1, sizeof(t_enemies));
	if (enemy == NULL)
		return (null_error("malloc error creating enemies - abort"));
	enemy->type = type;
	enemy->dir = 0;
	enemy->tile = tile;
	enemy->og_tile = enemy->tile;
	enemy->next = NULL;
	return (enemy);
}

/* returns pointer to last element of enemies struct */
t_enemies	*last_enemy(t_enemies *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* adds an enemy to end of game struct using memory allocation */
void	add_enemy(t_game *game, t_enemytypes type, t_tile *tile)
{
	t_enemies	*new;

	new = new_enemy(type, tile);
	if (new == NULL)
		return ;
	if (game->enemy_list == NULL)
		game->enemy_list = new;
	else
		last_enemy(game->enemy_list)->next = new;
}
