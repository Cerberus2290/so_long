/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:05:07 by tstrassb          #+#    #+#             */
/*   Updated: 2023/02/25 16:58:22 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	valid_char(char c);
int	valid_uniqchar(char c, char check, t_bool *bool);
int	valid_border(char c, t_vector point, t_vector size);

/// @brief checks if the Map file is valid
/// @return TRUE
int	valid_file(int argc, char *file)
{
	if (argc == 1)
		return (error("no .ber Mapfile found"));
	if (argc > 2)
		print_warning("only the first Mapfile will be used");
	if (!ft_strend_cmp(file, ".ber"))
		return (error("Mapfile needs the format <Mapname>.ber"));
	return (1);
}

/* initializes the map data to check if valid */
static t_mapdata	init_checkerdata(char **map)
{
	t_mapdata	data;

	data.size.x = ft_strlen(map[0]);
	data.size.y = ft_chart_linecount(map);
	data.b_player = FALSE;
	data.b_exit = FALSE;
	data.b_collect = FALSE;
	data.point.x = 0;
	data.point.y = 0;
	return (data);
}

/// @brief checks each individual tile of the map for errors
/// @return TRUE if no errors found
static int	checks(char **map, t_mapdata *data)
{
	int	x;
	int	y;

	x = data->point.x;
	y = data->point.y;
	if (!valid_char(map[y][x]))
		return (error("invalid map character found - abort"));
	if (!valid_uniqchar(map[y][x], 'P', &data->b_player))
		return (error("only one player tile allowed - abort"));
	if (!valid_border(map[y][x], data->point, data->size))
		return (error("map must be completely closed by '1' - abort"));
	if (map[y][x] == 'C')
		data->b_collect = TRUE;
	return (TRUE);
}

/// @brief checks if entire map is valid
/// @return FALSE and printing an error message otherwise TRUE
int	valid_map(char **map)
{
	t_mapdata	data;
	t_bool		valid;

	data = init_checkerdata(map);
	valid = TRUE;
	while (map[data.point.y])
	{
		if (ft_strlen(map[data.point.y]) != data.size.x)
			valid = error("map mus be in shape of rectangle - abort");
		data.point.x = 0;
		while (map[data.point.y][data.point.x])
		{
			if (checks(map, &data) == FALSE)
				valid = TRUE;
			data.point.x++;
		}
		data.point.y++;
	}
	if (!data.b_player || !data.b_exit || !data.b_collect)
		valid = error("map must have one 'P' and 'E' and at least one 'C'");
	return (valid);
}
