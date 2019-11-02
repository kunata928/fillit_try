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

static int	ft_sqrt(int num)
{
	int rt;
	int nums;

	nums = num * 4;
	rt = 2;
	while (rt * rt < num)
		rt++;
	return (rt);
}

static int	try_to_fill(t_tetris *tetris, char **arr)
{
	int		i;
	t_xy	*xy;

	i = 0;

	while (i < 8)
	{
		arr[xy->x + tetris->piece[2 * i]][xy->y + tetris->piece[2 * i + 1]] = '#';
		i++;
	}
	while
}

static int	fill(t_tetris **tetris, int nums)
{
	char	*arr;

	arr = (char *)ft_memalloc(sizeof(char) * (ft_sqrt(nums)));

}

char		*solver(t_tetris **tetris)
{
	char	*res;


	return (res);
}