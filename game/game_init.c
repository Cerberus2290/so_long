/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 11:50:07 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/06 11:16:30 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../map/map.h"

void	open_images(t_game *game);
t_tile	**generate_tilemap(char **map, t_game *game);

/* generates tilemap from first file of [argv]
returns NULL if any error occurs */
t_tile	**map_init(int argc, char **argv, t_game *game)
{
	char	**map;
	t_tile	**tilemap;

	if (!valid_file(argc, argv[1]))
		return (NULL);
	map = read_map(argv[1]);
	if (!map)
		return (NULL);
	if (valid_map(map) == FALSE)
	{
		ft_free_chartable(map);
		return (NULL);
	}
	tilemap = generate_tilemap(map, game);
	ft_free_chartable(map);
	if (!tilemap)
		return (NULL);
	return (tilemap);
}

/* initializes mlx, open new window and images */
void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->window_size.x + IMG_SIZE / 2,
			game->window_size.y, "so_long");
	mlx_hook(game->window, 17, 0, end_program, game);
	open_images(game);
	game->white_panel = new_panel(game, new_color(254, 254, 254, 0));
	game->red_panel = new_panel(game, new_color(197, 4, 4, 0));
}

/* set frames for animations */
static void	anima_setup(t_game *game)
{
	game->player.frames_idle = 17;
	game->player.frames_action = 10;
	game->collect_imgs.anima_frames = 25;
	game->effect.frames = 7;
	game->enemy_imgs.basic_anim = 16;
	game->enemy_imgs.follow_anim = 6;
}

/* starts the [game] struct */
t_bool	start(t_game *game, int argc, char **argv)
{
	game->collects = 0;
	game->moves = 0;
	game->tilemap = map_init(argc, argv, game);
	if (game->tilemap == NULL)
		return (FALSE);
	game->og_collects = game->collects;
	anima_setup(game);
	game_init(game);
	return (TRUE);
}
