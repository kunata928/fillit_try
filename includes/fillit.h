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

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF 600

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_tetris
{
	int				*piece;
	char			letter;
}				t_tetris;

typedef struct	s_data
{
	int count;
	int i;
	int fst;
}				t_data;

typedef struct	s_xy
{
	int		x;
	int		y;
}				t_xy;
t_tetris	**parsing(int fd, int *nums);
void	print_tetris(t_tetris **tetris, int nums);
void	error();

# endif
