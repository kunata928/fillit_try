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

static void		forchest(t_data *data, char *buff, int *piece)
{
	if (!has_neighbour(data->i, buff))
		error();
	if (!(data->count))
	{
		(piece[0]) = 0;
		(piece[1]) = 0;
		data->fst = data->i;
	}
	else
	{
		(piece[(2*(data->count))]) = (data->i) / 5  - (data->fst) / 5 ;
		(piece[2*(data->count) + 1]) = (data->i + 1) % 5 - (data->fst + 1) % 5;
	}
}

void		error()
{
	ft_putstr("error\n");
	exit(1);
}

static void		tetrimina(char *buff, t_tetris *tetris, int num)
{
	t_data *data;

	data = (t_data *)ft_memalloc(sizeof(t_data));
	while (data->i < 20 && data->count < 5)
	{
		if (((data->i + 1) % 5) == 0)
		{
			if (buff[data->i] != '\n')
				error();
			else
			{
				data->i += 1;
				continue;
			}
		}
		if (buff[data->i] == '#')
		{
			forchest(data, buff, tetris->piece);
			data->count += 1;
		}
		else if (buff[data->i] != '.')
			error();
		data->i++;
	}
	if (data->i != 20 || data->count != 4 || buff[20] != '\n')
		error();
	free(data);
	data = NULL;
	return ;
}

static void		another_format(t_tetris **tetris, int nums)
{
	int num;
	int j;
	int neg;

	num = 0;
	while (num < nums)
	{
		j = 0;
		while (j < 8)
		{
			if ((tetris[num]->piece)[j] < 0)
			{
				neg = (tetris[num]->piece)[j];
				(tetris[num]->piece)[1] -= neg;
				(tetris[num]->piece)[3] -= neg;
				(tetris[num]->piece)[5] -= neg;
				(tetris[num]->piece)[7] -= neg;
				j = 7;
			}
			j++;
		}
		num++;
	}
	return ;
}

t_tetris		**parsing(int fd, int *nums)
{
	t_tetris	**tetris;
	char		buff[BUFF];
	int			*piece;
	int			len;

	len = read(fd, buff, BUFF);
	if ((len - 20) % 21 != 0)
		error();
	else
	{
		buff[len] = '\n';
		*nums = (len - 20) / 21 + 1;
		tetris = (t_tetris **)ft_memalloc(sizeof(t_tetris *) * (*nums));
		len = 0;
		while (len < *nums)
		{
			tetris[len] = (t_tetris *)ft_memalloc(sizeof(t_tetris));
			tetris[len]->piece = (int *)ft_memalloc(sizeof(int) * 8);
			(tetris[len])->letter = 'A' + len;
			tetrimina(buff + len * 21, tetris[len], len);
			len++;
		}
	}
	another_format(tetris, *nums);
	return (tetris);
}
