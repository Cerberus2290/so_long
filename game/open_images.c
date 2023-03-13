/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:43:31 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/13 11:26:26 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	open_wall_imgs_up(t_game *game);
void	open_wall_imgs_down(t_game *game);

static void	open_player_imgs(t_game *game)
{
	game->player.idle_img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_01.xpm", &game->img_size.x, &game->img_size.y);
	game->player.idle_img_1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_02.xpm", &game->img_size.x, &game->img_size.y);
	game->player.action_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/player_03.xpm", &game->img_size.x, &game->img_size.y);
	game->player.current_img = game->player.action_img;
}

static void	open_collect_imgs(t_game *game)
{
	game->collect_imgs.img_0 = mlx_xpm_file_to_image(game->mlx,
			"sprites/pcb_03.xpm", &game->img_size.x, &game->img_size.y);
	game->collect_imgs.img_1 = mlx_xpm_file_to_image(game->mlx,
			"sprites/pcb_04.xpm", &game->img_size.x, &game->img_size.y);
	game->collect_imgs.current_img = game->collect_imgs.img_0;
	game->effect.img = mlx_xpm_file_to_image(game->mlx,
			"sprites/effect_w.xpm", &game->img_size.x, &game->img_size.y);
}

static void	open_enemy_imgs(t_game *game)
{
	game->enemy_imgs.basic_01 = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemy_01.xpm", &game->img_size.x, &game->img_size.y);
	game->enemy_imgs.basic_02 = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemy_02.xpm", &game->img_size.x, &game->img_size.y);
	game->enemy_imgs.basic_current = game->enemy_imgs.basic_01;
	game->enemy_imgs.follow_01 = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemy_03.xpm", &game->img_size.x, &game->img_size.y);
	game->enemy_imgs.follow_02 = mlx_xpm_file_to_image(game->mlx,
			"sprites/enemy_04.xpm", &game->img_size.x, &game->img_size.y);
	game->enemy_imgs.follow_current = game->enemy_imgs.follow_01;
}

static void	open_portal_imgs(t_game *game)
{
	game->door_open_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/portal_01.xpm", &game->img_size.x, &game->img_size.y);
	game->door_close_img = mlx_xpm_file_to_image(game->mlx,
			"sprites/portal_02.xpm", &game->img_size.x, &game->img_size.y);
}

/* opens all *.xpm files from "sprites/" used in game */
void	open_images(t_game *game)
{
	open_wall_imgs_up(game);
	open_wall_imgs_down(game);
	open_player_imgs(game);
	open_collect_imgs(game);
	open_enemy_imgs(game);
	open_portal_imgs(game);
}
