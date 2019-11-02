/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	print_tetris(t_tetris **tetris, int nums)
{
	int i;
	int j;

	i = 0;
	while (i < nums)
	{
		j = 0;
		while (j < 8)
		{
			ft_putnbr(tetris[i]->piece[j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return ;
}
