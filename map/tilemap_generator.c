/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilemap_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 09:45:49 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/13 10:08:50 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/* using memory allocation saves a tilemap with same size as [map] */
t_tile	**alloc_tilemap(char **map)
{
	t_tile	**tilemap;
	int		i;

	tilemap = malloc(sizeof(t_tile *) * ft_chartable_linecount(map) + 1);
	if (tilemap == NULL)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		tilemap[i] = malloc(sizeof(t_tile) * ft_strlen(*map) + 1);
		if (tilemap == NULL)
		{
			while (i > 0)
				free(tilemap[--i]);
			return (NULL);
		}
		i++;
	}
	return (tilemap);
}

/* return tiletype from struct maptiles to [definition] */
t_maptiles	define_tiletype(char definition)
{
	if (definition == '1')
		return (WALL);
	if (definition == 'C')
		return (COLLECTABLE);
	if (definition == 'P')
		return (PLAYER);
	if (definition == 'E')
		return (EXIT);
	if (definition == 'H' || definition == 'V')
		return (ENEMY);
	if (definition == 'A')
		return (VALID);
	else if (definition == 'F')
		return (FOLLOWER);
	return (EMPTY);
}

/* sets size, original type and coordinates of [x][y] tile of [tilemap] */
void	setup_tiles(t_tile **tilemap, int x, int y)
{
	tilemap[y][x].og_type = tilemap[y][x].type;
	tilemap[y][x].position.x = x * IMG_SIZE;
	tilemap[y][x].position.y = y * IMG_SIZE;
	if (y != 0)
		tilemap[y][x].up = &tilemap[y - 1][x];
	if (tilemap[y + 1] != NULL)
		tilemap[y][x].down = &tilemap[y + 1][x];
	if (x != 0)
		tilemap[y][x].left = &tilemap[y][x - 1];
	tilemap[y][x].right = &tilemap[y][x + 1];
}

/* adds unique characters if present */
void	set_gamevars(t_tile *tile, t_game *game, char c)
{
	if (tile->type == PLAYER)
		game->player.tile = tile;
	else if (tile->type == COLLECTABLE)
		game->collects++;
	else if (tile->type == ENEMY || tile->type == FOLLOWER)
		add_enemy(game, c, tile);
}

/* generates a t_tile table with info from [map],
each line ending in tile of type '0',
each column ending in NULL pointer */
t_tile	**generate_tilemap(char **map, t_game *game)
{
	t_tile	**tilemap;
	int		x;
	int		y;

	tilemap = alloc_tilemap(map);
	if (!tilemap)
		return (null_error("malloc error in map file - abort"));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			tilemap[y][x].type = define_tiletype(map[y][x]);
			setup_tiles(tilemap, x, y);
			set_gamevars(&tilemap[y][x], game, map[y][x]);
			x++;
		}
		tilemap[y][x].type = 0;
		y++;
	}
	tilemap[y] = NULL;
	game->window_size.x = x * IMG_SIZE;
	game->window_size.y = y * IMG_SIZE;
	return (tilemap);
}
