/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:38:50 by tstrassb          #+#    #+#             */
/*   Updated: 2023/01/05 10:07:04 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*	if BUFFER_SIZE is undefined by user
	BUFFER_SIZE is globally defined here: */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 124
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

size_t		ft_strlen(char *s);
char		*ft_strchr(char *c, int i);
char		*ft_strjoin(char *str1, char *buffer);
char		*ft_line_get(char *str1);
char		*ft_line_new(char *str1);
char		*get_next_line(int fd);

#endif
