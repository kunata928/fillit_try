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

static int		has_neighbour(int i, char *buff)//this function check/ if # has near other #
{
	if (i != 0)
	{
		if (buff[i - 1] == '#')
			return (1);
	}
	if (buff[i + 1] == '#')
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

static char		*clean_memory()
{
	return (0);
}

static void		forchest(t_data *data, char *buff, char **piece)
{
	if (!has_neighbour(data->i, buff))
		clean_memory();
	if (!(data->count))
	{
		piece[0] = 0;
		piece[1] = 0;
		data->fst = data->i;
	}
	else
	{
		piece[2*(data->count)] = (data->i + 1) % 5 - (data->fst + 1) % 5;
		piece[2*(data->count) + 1] = data->i / 5  - data->fst / 5;
	}
}

static char		*tetrimina(char *buff, char **piece)
{
	t_data *data;

	data->count = 0;
	while (data->i < 20 && data->count < 4)
	{
		if (((data->i + 1) % 5) == 0 && buff[data->i] != '\n')
			return (0);
		if (buff[data->i] == '#')
		{
			forchest(data, buff, piece);
			data->count += 1;
		}
		else if (buff[data->i] != '.')
			return (0);
		data->i++;
	}
	if (data->i != 4 || buff[21] != '\n')
		return (clean_memory());
	return (0);
}

t_tetris		*parsing(int fd)
{
	t_tetris	*tetris;
	int			len;
	char 		*buff;
	char		*piece;

	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	if ((len = read(fd, buff, BUFF)) == 21) //read 21 symbols
	{
		//if there are right tetrimina malloc memory for it and add link for it array
		//else clean memory
		if (!(piece = (char *)malloc(sizeof(char) * 9)))
			return (0);
		piece[8] = '\0';
		tetrimina(buff, &piece);
		if(!(tetris = (t_tetris *)ft_memalloc(sizeof(t_tetris))))
			return (NULL);

	}
	return (NULL);
	return(tetris);
}