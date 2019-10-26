/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_FILLIT_H
# define FILLIT_FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <gssapi.h>
# include "libft.h"
# define BUFF 21

typedef struct	s_tetris
{
	char			*piece;
	char			letter;
	struct s_tetris	*next;
}				t_tetris;

typedef struct	s_data
{
	int count;
	int i;
	int fst;
}				t_data;

static t_tetris	*parsing(int fd);

#endif FILLIT_FILLIT_H
