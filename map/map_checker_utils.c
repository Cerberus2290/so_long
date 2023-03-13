/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 08:38:11 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/13 10:30:23 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

/// @brief checks if map tile is valid character
/// @param c valid map tile character (defined in "so_long.h")
/// @return TRUE
int	valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P'
		|| c == 'H' || c == 'V' || c == 'F' || c == 'A')
		return (TRUE);
	return (FALSE);
}

/* function to turn [bool] to TRUE if [c] is equal [check]
returns FALSE if [bool] is TRUE already*/
int	valid_uniqchar(char c, char check, t_bool *bool)
{
	if (c == check && *bool == FALSE)
		*bool = TRUE;
	else if (c == check && *bool == TRUE)
		return (FALSE);
	return (TRUE);
}

/// @brief checks if map border is valid
/// @return FALSE if [point] is in border and [c] is not '1'
int	valid_border(char c, t_vector point, t_vector size)
{
	if (point.y == 0 || point.x == 0
		|| point.y == size.y - 1 || point.x == size.x - 1)
		if (c != '1')
			return (FALSE);
	return (TRUE);
}
