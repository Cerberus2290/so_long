/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:20:02 by tstrassb          #+#    #+#             */
/*   Updated: 2023/02/25 14:33:21 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/ft_printf.h"

int	error(char *message)
{
	ft_printf("\033[0;31m" "Error\n %s\n" "\033[0m", message);
	return (0);
}

void	*null_error(char *message)
{
	ft_printf("\033[0;31m" "Error\n %s\n" "\033[0m", message);
	return (0);
}

void	print_warning(char *message)
{
	ft_printf("\033[0;33m" "Warning\n %s\n" "\033[0m", message);
}
