/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:41:45 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/08 09:20:54 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_tilemap(t_game *game)
{
	t_tile	**tilemap;

	tilemap = game->tilemap;
	while (*game->tilemap != NULL)
	{
		free(*game->tilemap);
		game->tilemap++;
	}
	free (tilemap);
}

void	free_enemies(t_game *game)
{
	t_enemies	*next;

	if (game->enemy_list == NULL)
		return ;
	while (TRUE)
	{
		next = game->enemy_list->next;
		printf("%p\n%p\n", next, game->enemy_list);
		free (game->enemy_list);
		if (next == NULL)
			break ;
		game->enemy_list = next;
	}
}

/* frees all memory and makes exit(0) */
int	end_program(t_game *game)
{
	free_tilemap(game);
	game->tilemap = NULL;
	game->enemy_list = NULL;
	exit(0);
}
