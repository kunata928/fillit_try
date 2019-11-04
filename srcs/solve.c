/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static char	**ft_sqrt(int num, char **arr)
{
	int rt;
	int nums;
	int i;

	nums = num * 4;
	rt = 2;
	i = 0;
	while (rt * rt < nums)
		rt++;
	arr = (char **)ft_memalloc(sizeof(char *) * rt);
	while (i < rt)
	{
		arr[i] = (char *)ft_memalloc(sizeof(char) * 8);
		i++;
	}
	return (arr);
}

static int	try_to_fill(t_tetris *tetris, char **arr, t_xy xy0)
{
	int		i;
	t_xy	xy;

	i = 0;
	while (i < 4)
	{
		xy.x = xy0.x + tetris->piece[2 * i];
		xy.y = xy0.y + tetris->piece[2 * i + 1];
		if (!arr[xy.x][xy.y])
			arr[xy.x][xy.y] = '#';
		else
			return (0);
		i++;
	}
	return (1);
}

static int	fill(t_tetris **tetris, int nums)
{
	char	**arr;
	int i;
	t_xy xy0;

	i = 0;
	xy0.x = 0;
	xy0.y = 0;
	arr = ft_sqrt(nums, arr); // create 2dem array start size
	while (i < nums)
	{
		try_to_fill(tetris[i], arr, xy0);
		i++;
	}
	return (0);
}

char		*solver(t_tetris **tetris)
{
	char	*res;


	return (res);
}