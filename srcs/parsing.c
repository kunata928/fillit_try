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

static void		clean_memory()
{
	return ;
}

static void		forchest(t_data *data, char *buff, int **piece)
{
	if (!has_neighbour(data->i, buff))
		error();
	if (!(data->count))
	{
		*(piece[0]) = 0;
		*(piece[1]) = 0;
		data->fst = data->i;
	}
	else
	{
		*(piece[2*(data->count)]) = (data->i + 1) % 5 - (data->fst + 1) % 5;
		*(piece[2*(data->count) + 1]) = (data->i) / 5  - (data->fst) / 5;
	}
}

void		error()
{
	ft_putstr("error\n");
	exit(1);
}

static void		tetrimina(char *buff, int **piece, t_tetris **tetris)
{
	t_data *data;

	data->count = 0;
	data->i = 0;
	while (data->i < 20 && data->count < 4)
	{
		if (((data->i + 1) % 5) == 0)
		{
			if (buff[data->i] != '\n')
				error();
			else
			{
				data->i++;
				continue;
			}
		}
		if (buff[data->i] == '#')
		{
			forchest(data, buff, piece);
			data->count += 1;
		}
		else if (buff[data->i] != '.')
			error();
		data->i++;
	}
	if (data->i != 20 || data->count != 4 || buff[21] != '\n')
		error();
	return ;
}

static t_tetris	*new_elem(int **piece)
{
	t_tetris	*list;

	if (!(list = (t_tetris *)ft_memalloc(sizeof(t_tetris))))
		return (NULL);
	list->piece = *piece;
	list->letter = 'A';
	list->next = NULL;
	return (list);
}

t_tetris		*parsing(int fd)
{
	t_tetris	*tetris;
	t_tetris	*tmp;
	char 		buff[BUFF + 1];
	int			*piece;
	int			len;


	if (fd < 0 || read(fd, NULL, 0) < 0)
		error();
	tetris = NULL;
	len = (read(fd, buff, BUFF));
	if (len == 21) //read 21 symbols
	{
		//if there are right tetrimina malloc memory for it and add link for it array
		//else clean memory
		if (!(piece = (int *)malloc(sizeof(int) * 8)))
			return (0);
		tetrimina(buff, &piece, &tetris);
		tmp = new_elem(&piece);
		tmp->next = tetris;
		tetris = tmp;
	}
	return(tetris);
}