/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:59:34 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/06 09:32:26 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include <fcntl.h>
#include <unistd.h>
#include "../gnl/get_next_line.h"

/* counts how many '\\n' are in map file
Returns amount */
static int	mapfile_countlines(char *file)
{
	int		linecount;
	int		fd;
	int		readcount;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	while (TRUE)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
	return (linecount);
}

/* memory allocation for a string array with the same lines as map file */
static char	**alloc_collums(char *file)
{
	char	**map;
	int		line_count;

	line_count = mapfile_countlines(file);
	if (line_count <= 0)
		return (null_error("error opening or reading map - file may not exist or is empty"));
	map = malloc(sizeof(char *) * line_count + 1);
	if (map == NULL)
		return (null_error("error allocating memory in alloc_collums - abort"));
	return (map);
}

/* creates a 2D map - exactly like map file using memory allocation*/
char	**read_map(char *file)
{
	char	**map;
	int		fd;
	int		i;

	map = alloc_collums(file);
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &map[i++]))
		;
	map[i] = NULL;
	close(fd);
	return (map);
}
