/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static int		has_neighbour(int i, char *buff)
{
	if (buff[i - 1] == '#' || buff[i + 1] == '#')
		return (1);
	if (i > 4)
	{
		if (buff[i - 5] == '#')
			return (1);
	}
	if (i < 14)
	{
		if (buff[i + 5] == '#')
			return (1);
	}
	return (0);
}

static char		*tetrimina(char *buff, char **piece)
{
	int		count;
	int		i;
	int		first;

	i = 0;
	first = 0;
	while (i < 20 && count < 4)
	{
		if (((i + 1) % 5) == 0 && buff[i] != '\n')
			return (0);
		else if (buff[i] == '#')
		{
			if (!first)
				first = 1;
			else
				return(has_neighbour(i, buff));
			count++;
		}
		else if (buff[i] != '.')
			return (0);
		i++;
	}
	if (i != 4 || buff[21] != '\n')
		return (0);
	return ();
}

t_tetris		*parsing(int fd)
{
	t_tetris	*tetris;
	int			len;
	char 		*buff;

	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	if ((len = read(fd, buff, BUFF)) == 21)
	{
		if(!(tetris = (t_tetris *)ft_memalloc(sizeof(t_tetris))))
			return (NULL);
		tetrimina(buff, &(tetris->piece));
	}
	return (NULL);
	return(tetris);
}