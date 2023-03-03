/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:12:18 by tstrassb          #+#    #+#             */
/*   Updated: 2023/02/26 10:54:51 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_H
# define BASIC_H

# include "libft/include/libft.h"
# include "libft/include/ft_printf.h"

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_vector
{
	int		x;
	int		y;
}	t_vector;

int		error(char *message);
void	*null_error(char *message);
void	print_warning(char *message);

#endif