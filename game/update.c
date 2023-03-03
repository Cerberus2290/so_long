/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:14:52 by tstrassb          #+#    #+#             */
/*   Updated: 2023/02/28 16:00:41 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	player_animation(t_player *player)
{
	if (player->current_img == player->action_img
		&& player->framecount >= player->frames_action)
	{
		player->current_img = player->idle_img_1;
	}
	else if (player->framecount == player->frames_idle)
	{
		player->current_img = player->idle_img_0;
	}
	else if (player->framecount >= player->frames_idle * 2)
	{
		player->current_img = player->idle_img_1;
		player->framecount = 0;
	}
	player->framecount += 1;
}

static void	collect_animation(t_collect_img *img)
{
	static int	frame;

	if (img->anima_frames == 0)
		return ;
	if (frame == img->anima_frames)
	{
		img->current_img = img->img_0;
	}
	else if (frame >= img->anima_frames * 2)
	{
		img->current_img = img->img_1;
		frame = 0;
	}
	frame += 1;
}

static void	enemy_animation(t_enemy_anim *img)
{
	static int	std_count;
	static int	follower_count;

	if (std_count == img->basic_anim)
		img->basic_current = img->basic_01;
	else if (std_count > img->basic_anim * 2)
	{
		img->basic_current = img->basic_02;
		std_count = 0;
	}
	std_count++;
	if (follower_count == img->follow_anim * 2)
		img->follow_current = img->follow_01;
	else if (follower_count > img->follow_anim * 2)
	{
		img->follow_current = img->follow_02;
		follower_count = 0;
	}
	follower_count++;
}

/* calculates all animation and render
function is called once every frame */
int	update(t_game *game)
{
	player_animation(&game->player);
	collect_animation(&game->collect_imgs);
	enemy_animation(&game->enemy_imgs);
	render(*game);
	return (1);
}
