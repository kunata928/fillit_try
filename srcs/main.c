/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelodi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:04:39 by pmelodi           #+#    #+#             */
/*   Updated: 2019/09/16 22:04:54 by pmelodi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int ac, char **av)
{
	int			fd;
	int			nums;
	t_tetris	**tetris;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
	}
	fd = open("/Users/pmelodi/Projects/fillit/tetris", O_RDONLY);
	tetris = parsing(fd, &nums);
	print_tetris(tetris, nums);
	ft_putstr("parsing done");

	close(fd);
	return (0);
}