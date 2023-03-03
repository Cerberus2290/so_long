/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:04:59 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/02 10:24:12 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* returns the struct t_color */
t_color	new_color(int r, int g, int b, int a)
{
	t_color	color;

	color.r = (char)r;
	color.g = (char)g;
	color.b = (char)b;
	color.a = (char)a;
	return (color);
}

/* paints all pixels in [panel] to [color] */
void	color_panel(t_img_entire *panel, t_color color)
{
	int	x;
	int	y;

	panel->pixels = mlx_get_data_addr(panel->pointer, &panel->bpp,
			&panel->line_size, &panel->endian);
	y = 0;
	while (y < panel->size.y)
	{
		x = 0;
		while (x < panel->size.x)
		{
			panel->pixels[(x * 4 + panel->line_size * y) + 0] = color.b;
			panel->pixels[(x * 4 + panel->line_size * y) + 1] = color.g;
			panel->pixels[(x * 4 + panel->line_size * y) + 2] = color.r;
			panel->pixels[(x * 4 + panel->line_size * y) + 3] = color.a;
			x += 1;
		}
		y += 1;
	}
}

/* creates a colored image of same size as window */
void	*new_panel(t_game *game, t_color color)
{
	t_img_entire	panel;

	panel.pointer = mlx_new_image(game->mlx,
			game->window_size.x, game->window_size.y);
	panel.size.x = game->window_size.x;
	panel.size.y = game->window_size.y;
	color_panel(&panel, color);
	return (panel.pointer);
}
